#include <gtest/gtest.h>
#include <sqlite3.h>
#include <sstream>
#include <string>
#include <string.h>

using namespace std;

TEST(CStringNullTermination, BuildFromChars) {
  string buildFromChars;
  buildFromChars.push_back('c');

  ASSERT_EQ(1, strlen(buildFromChars.c_str()));
}

TEST(CStringNullTermination, FromCharPointer) {
  string fromCharPointer = "Hello World";
  ASSERT_EQ(11, strlen(fromCharPointer.c_str()));
}

class SqliteQuery {
  public:
    SqliteQuery() {
      database_file_ = "query_test.sqlite3";
      query_ = "SELECT english from translations where italian = ?";
      delete_database();
      connect();
      create_table();
      insert_rows();
      prepare();
    };

    ~SqliteQuery() {
      disconnect();
      delete_database();
    }

    void bind(const string &italian) {
      sqlite3_bind_text(statement_, 1, italian.c_str(), italian.size(), 0);
    }

    string execute() {
      sqlite3_step(statement_);
      const char * value = (const char *) sqlite3_column_text(statement_, 0);
      string s = value;
      return s;
    }

  private:
    void delete_database() {
      string remove_database = "rm -f " + database_file_;
      system(remove_database.c_str());
    };

    void connect() {
      sqlite3_open(database_file_.c_str(), &db_);
    }

    void create_table() {
      string create_table = "CREATE TABLE translations (italian TEXT, english TEXT);";
      sqlite3_stmt * statement;
      sqlite3_prepare_v2(db_, create_table.c_str(), create_table.size(), &statement, 0);
      sqlite3_step(statement);
      sqlite3_finalize(statement);
    }

    void insert_rows() {
      string insert = "INSERT INTO translations VALUES (\"ciao\", \"hello\");";
      sqlite3_stmt * statement;
      sqlite3_prepare_v2(db_, insert.c_str(), insert.size(), &statement, 0);
      sqlite3_step(statement);
      sqlite3_finalize(statement);
    }

    void prepare() {
      sqlite3_prepare_v2(db_, query_.c_str(), query_.size(), &statement_, 0);
    }

    void disconnect() {
      sqlite3_close(db_);
    }

    string           database_file_;
    sqlite3 *        db_;
    string           query_;
    sqlite3_stmt *   statement_;
};

TEST(SqliteQuery, BindAndExecute) {
  SqliteQuery qry;
  qry.bind("ciao");
  string result = qry.execute();

  ASSERT_STREQ("hello", result.c_str());
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int result = -1;
  return RUN_ALL_TESTS();
}
