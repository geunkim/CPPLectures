#연관 컨테이너(Associative Container)

## map 
키-값(key-value) 쌍으로 데이터를 저장하는 컨테이너로 클래스 템플릿(class template)이다. 컨테이너 내의 key 값은 유일하여야 하며 kye 값으로 졍렬(sort)된다. 



```c++
template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T>>
> class map;
```



## set 
키(key)로 이루어진 데이터를 저장하는 컨테이너로 클래스 템플릿(class template)이다. 컨테이너 내의 key 값은 유일하여야 하며 key 값으로 졍렬(sort)된다. 

```c++
template<
    class Key,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<Key>
> class set;
```



## multimap
키-값(key-value) 쌍으로 데이터를 저장하는 컨테이너로 클래스 템플릿(class template)이다. ``map``과 같이 key 값으로 정렬되나 컨테이너 내의 key 값이 종복되어도 딘다. 

```c++
template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T>>
> class multimap;
```


## multiset
키(key)로 이루어진 데이터를 저장하는 컨테이너로 클래스 템플릿(class template)이다. 컨테이너 내의 key 값은 중복이 되어도 되나 key 값으로 졍렬(sort)된다. 

```c++
template<
    class Key,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<Key>
> class multiset;
```
