## REQUIRE

### stl路径
- mac mini `/Library/Developer/CommandLineTools/SDKs/MacOSX15.2.sdk/usr/include/c++/v1`
- archlinux `/usr/include/c++/15.2.1/bits/stl_vector.h`

### 拷贝源码
#### vector 
```sh
cp -R /Library/Developer/CommandLineTools/SDKs/MacOSX15.2.sdk/usr/include/c++/v1/vector stl/libcxx 
```

## NOTE
- vector
  - [X] push_back
