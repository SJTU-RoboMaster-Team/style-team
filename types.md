## 类型和约束

### 单行格式化

* `T name[expr]`，例如 `uint32_t a[32]`, `std::vector<Foo> a[10 * 2 + foo()]`（中括号两边没有空格）
* `const T* name`, `T& name`（`*` 和 `&` 与类型名之间没有空格，与变量名之间有一个空格）
* `template<typename T, typename U>`（逗号后有一个空格，尖括号两边没有空格）
* `std::tuple<A, B, C, D>` （逗号后有空格，尖括号两边没有空格）
* `class A: public B, public C {}` （冒号和逗号尾随类型名）。

### 分行

避免在类型中分行。如果要分行，尽量在最外层分行。例如，这种写法

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

Function types may be broken following the rules for function declarations.

Generic types may be broken following the rules for generics.

Types with `+` may be broken after any `+` using block indent and breaking before the `+`. When breaking such a type, all `+`s should be line broken, e.g.,

```cpp
class A:
    public Clone,
    public Copy,
    public Debug {
private:
    int a;
    int b;
};
```
