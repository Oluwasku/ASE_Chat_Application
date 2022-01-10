#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio/io_context.hpp>


using namespace boost::asio;
using ip::tcp;
using std::cout;
using std::endl;

/**
 * @brief The con_handler class
 */
class con_handler : public boost::enable_shared_from_this<con_handler>
{
private:
  tcp::socket sock;
  std::string message="Hello From ASE Server!";
  enum { max_length = 1024 };
  char data[max_length];

public:

typedef boost::shared_ptr<con_handler> pointer;
 con_handler(boost::asio::io_context& io_context)
    : sock(io_context)
  {
  }

  static pointer create(boost::asio::io_context& io_context)
  {
    return pointer(new con_handler(io_context));
  }

  tcp::socket& socket()
  {
    return sock;
  }

  /**
   * @brief start
   */
  void start()
  {
    sock.async_read_some(
        boost::asio::buffer(data, max_length),
        boost::bind(&con_handler::handle_read,
                    shared_from_this(),
                    boost::asio::placeholders::error,
                    boost::asio::placeholders::bytes_transferred));


    sock.async_write_some(
    boost::asio::buffer(message, max_length),
        boost::bind(&con_handler::handle_write,
            shared_from_this(),
                boost::asio::placeholders::error,
                boost::asio::placeholders::bytes_transferred));
  }


  void handle_read(const boost::system::error_code& err, size_t bytes_transferred)
  {
    if (!err) {
      cout << data << endl;

    } else {
std::cerr << "err (recv): " << err.message() << std::endl;
      sock.close();
    }
  }
  void handle_write(const boost::system::error_code& err, size_t bytes_transferred)
  {
    if (!err) {

    cout << "Server sent Hello message!"<< endl;

    } else {
      std::cerr << "err (recv): " << err.message() << std::endl;
      sock.close();
    }
  }

};


/**
 * @brief The Server class
 */
class Server
{

private:
  tcp::acceptor acceptor_;
  boost::asio::io_context io_context;

public:
  //tcp::acceptor acceptor_;
void start_accept()
  {
    // creates a socket
    con_handler::con_handler::pointer connection =
      con_handler::con_handler::create(io_context);

    // initiates an asynchronous accept operation
    // to wait for a new connection.
    acceptor_.async_accept(connection->socket(),
        boost::bind(&Server::handle_accept, this, connection,
          boost::asio::placeholders::error));
  }
//public:
  Server(boost::asio::io_context& io_context): acceptor_(io_context, tcp::endpoint(tcp::v4(), 1234))
  {
     start_accept();
  }

  void handle_accept(con_handler::pointer connection,
                     const boost::system::error_code& err)
  {
    if (!err) {
      connection->start();
    }
    start_accept();
  }

};

