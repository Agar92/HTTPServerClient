#include "connection_manager.hpp"

#include <iostream>

namespace http {
namespace server {

connection_manager::connection_manager()
{
  std::cout<<"connection_manager()"<<std::endl;
}

connection_manager::~connection_manager()
{
  std::cout<<"~connection_manager()"<<std::endl;
}

void connection_manager::start(connection_ptr c)
{
  std::cout<<"connection_manager::start"<<std::endl;
  connections_.insert(c);
  c->start();
}

void connection_manager::stop(connection_ptr c)
{
  connections_.erase(c);
  c->stop();
}

void connection_manager::stop_all()
{
  for (auto c: connections_)
    c->stop();
  connections_.clear();
}

} // namespace server
} // namespace http