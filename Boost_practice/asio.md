### String 

```c++
Predicate and Classification

// iends_with(str, str)
bool is_executable(string& filename){
  return iends_with (filename, ".com") || is_executable(filename, ".exe");
}

string str1("web.mit.com");
cout << ( is_executable(str1) ? "is" : "is not") << endl;


```





**boost asio** provide long running operation without using concurrent model based on thread or lock

based on BSD Socket API(Berkeley sockets)

[MIT BSD Socket API](http://web.mit.edu/macdev/Development/MITSupportLib/SocketsLib/Documentation/sockets.html)

**POSIX** socket is essentially synchronous with Berkelekey sockets and called BSD socket 

Portable Operating System Interfaces

https://www.youtube.com/watch?v=U0GbJtnfqSM







## Range

concept similiar to the STL [container](http://www.cplusplus.com/reference/stl/)

1. **sequence container:** array, vector, deque, forward_list, list
2. **container adaptor:** stack, queue, priority_queue
3. **associative containers:** set, map, multiset, multimap
4. **unorder associative container: ** unordered_set, unordered_map, 



Range object must be passed by **(const or non-const)** reference in generic code.







**behaviors of range** is determined by their **associated adaptors**

Iterate over map_keys

Iterate over map_value

```
for_each(my_map | map)
```

Filter all the even map_value and reverse the order

```
for_each(my_map | map_value | filtered(is_even()) | reveresed )
```

## Iterator:

issue: current iterator use single hierarchy to address the orthogonal issues: iterator traverse and value access



