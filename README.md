## REQUIRE

stl源码拷贝 linux平台可以把整个源码拷贝过来 但是mac平台不行 需要哪个拷贝哪个

- mac mini `cp -R /Library/Developer/CommandLineTools/SDKs/MacOSX15.2.sdk/usr/include/c++/v1/* ./stl/libcxx/`
- archlinux `cp -R /usr/include/c++/15.2.1/* ./stl/libstdcxx/`

## NOTE
- vector
  - [X] 构造函数 
  - [X] 析构函数
  - [X] =
  - [X] assign
  - [X] get_allocator
  - [X] at
  - [X] []
  - [X] front
  - [X] back
  - [X] data
  - [X] 迭代器 begin end
  - [X] empty
  - [X] size
  - [X] max_size
  - [X] reserve
  - [X] push_back
  - [X] 
