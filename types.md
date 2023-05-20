## 类型

### 单行格式化

* `T name[expr]`，例如 `uint32_t a[32]`, `std::vector<Foo> a[10 * 2 + foo()]`（中括号两边没有空格）
* `const T* name`, `T& name`（`*` 和 `&` 与类型名之间没有空格，与变量名之间有一个空格）
* `template<typename T, typename U>`（逗号后有一个空格，尖括号两边没有空格）
* `std::tuple<A, B, C, D>` （逗号后有空格，尖括号两边没有空格）
* `class A: public B, public C {}` （冒号、逗号与类型名之间没有空格）。

### 分行

避免在类型中分行。如果要分行，最好在最外层分行。例如，这种写法

```cpp
Foo<
    Bar,
    Baz<Type1, Type2>,
>
```

比下面这个写法更好：

```cpp
Foo<Bar, Baz<
    Type1,
    Type2,
>>
```
