## 表达式
### 语句块

语句块在左大括号 `{` 之后和右大括号 `}` 之前都应有换行符。块前的任何限定符都应与 `{` 在同一行，且间隔一个空格。语句块中的内容应使用块缩进。

```cpp
void block_as_stmt() {
    a_call();

    {
        a_call_inside_a_block();

        // 语句块中的一条注释
        return the_value;
    }
}

void block_as_expr() {
    auto foo = [&]() {
        a_call_inside_a_block();

        // 语句块中的一条注释
        return the_value;
    }();
}
```

在语句块中的预处理指令的缩进应和其他表达式一致

```cpp
void block_as_stmt() {
    #ifdef a_definition
    {
        #define another_definition

        // 语句块中的一条注释
        #undef another_definition
    }
    #endif
}
```

不要在大括号的同一行中写注释。

空块的写法是 `{}`。

块在同时满足以下条件的情况下可以只占一行：

* 块以 lambda 表达式而非语句的形式出现
* 其中包含单行语句
* 其中不包含注释

单行语句块在左大括号前喝右大括号后都应有一个空格。

例如，

```cpp
void func() {
    // 单行
    int cnt0 = []() { return 2; }();

    // 以语句形式出现时
    {
        a_call();
    }

    // 包含注释
    int cnt1 = [&]() {
        // 注释
        return 2;
    }();

    // 包含多行语句
    int cnt2 = [&]() {
        if (cnt0 != 2) {
            return 3;
        } else {
            return 4;
        }
    }();
    int cnt3 = [&](){
        return a_call(
            an_argument,
            another_arg
        );
    }();
}
```

### 列表初始化

如果初始化列表是**小**的，则它可以放在一行。否则，初始化成员应该有自己的块缩进。多行初始化列表的最后一个参数应有尾随逗号。

左大括号 `{` 之前应有一个空格。在单行初始化列表中，左大括号后和右大括号前需有一个空格。

```cpp
Foo f1 = Foo { 1, 2, 3 };
Foo f2 = Foo {
    field1,
    an_expr,
};
```

### 数组访问

中括号两边不加空格，尽量避免换行。在目标表达式和左中括号之间不要空行。如果下标表达式有多行，应使用块缩进，而且左中括号之后和右中括号之前应换行。不过要避免多行的下标表达式。

例如，

```cpp
void func() {
    foo[10];
    foo[4 + 5 / bar];
    a_long_target[
        a_long_indexing_expression
    ];
}
```

### 一元运算符

一元运算符和操作数之间不应有空格（即 `!x` 而非 `! x`），避免一元运算符和操作数之间换行。

### 二元运算符

二元运算符和操作数之间应有空格。（即 `x + 1` 而非 `x+1`）（包括 `=` 和其他赋值运算符，例如 `+=` 或 `*=`）。

大方使用括号，不要因为运算符优先级就省略括号（比如，使用 `(a && b) || (c && d)` 而非 `a && b || c && d`，虽然他们表达的意思一致）。格式化工具不可添加或移除括号。不要使用括号来表明优先级。

如果表达式有多行，把运算符放在后一行，并且使用块缩进。各个子表达式独占一行。例如，

```cpp
foo_bar
    + bar
    + baz
    + qux
    + whatever
```

在赋值运算符（`=` 或 `+=` 等）处换行比在其他运算符处换行更好。

### 控制流

如果能增强可读性，可以在数学表达式和逻辑表达式中加上额外的括号（`(x * 15) + (y * 20)` 挺好的）。

### 函数调用

不要在函数名和左小括号之间加空格。

不要在参数和其尾随的逗号之间加空格。

在参数前的逗号和参数之间加空格。

调用最好写成单行的。

#### 单行调用

函数名与左括号，左括号和首个参数，最后一个参数和右小括号之间不要有空格。

```cpp
foo(x, y, z)
```

#### 多行调用

若函数不是**小**的，或者它会超出行宽限制，或者任何参数或参数的调用是多行的，则该调用应格式化为多行。该情况下，每个参数独占一行并使用块缩进。左小括号后、右小括号前应换行。例如，

```cpp
a_function_call(
    arg1,
    a_nested_call(a, b)
)
```

### 方法调用

和函数调用保持一致。

在 `.` 两边不要有空格。

```cpp
x.foo().bar().baz(x, y, z);
```

### 宏调用

如果宏可以像其他结构一样解析，则像其他结构一样格式化。例如 `FOO(a, b, c)` 可以被解析为一个函数调用（除了命名风格不同），所以它按照函数调用一样格式化。

### 域和方法调用链

调用链由域访问（`::`）和方法调用（`. 或 ->`）构成。

尽量写在单行内。如果需要写成多行，则所有元素应该独占一行，且以 `.` 作为新行的开头。每行都应使用块缩进。例如，

```cpp
int foo = bar
    .baz
    .qux();
```

如果一个调用链的第一个元素的最后一行加上其缩进小于下一行的缩进，则只要有足够的空间，就应合并这两行。例如，

```cpp
// 使用
x.baz
    .qux()
// 不使用
x
    .baz
    .qux()

// 使用
int foo = x
    .baz
    .qux();

foo(
    expr1,
    expr2
).baz
    .qux();
```

#### 多行元素

若一个调用链中的某个元素被格式化为多行，则该元素和其后的元素应独占一行。其前的元素可以写在同一行。例如，

```cpp
a.b.c().d
    .foo(
        an_expr,
        another_expr,
    )
    .bar
    .baz
```

注意在上述例子中，调用链和函数调用都造成了缩进。

将整个调用格式化为多行且每个元素独占一行，要优于把部分元素放在同一行而其他元素格式化为多行。例如，

```cpp
// 好的
this->pre_comment
    .as_ref()
    .map_or(false, [&](auto comment) { return comment.starts_with("//"); })

// 坏的
this->pre_comment.as_ref().map_or(
    false,
    [&](auto comment) { return comment.starts_with("//"); }
)
```

### 控制流表达式

这一部分适用于 `if`，`for`，`while`，`do-while` 表达式。

关键字、条件表达式和左大括号应在同一行。执行语句块应使用[语句块的格式化](#语句块)。

如果有 `else` 部分，则 `else` 之前的右大括号，`else`，接下来的条件表达式和左大括号都应在同一行。`else` 前后应有一个空格。例如：

```cpp
if (...) {
    ...
} else {
    ...
}

if (...) {
    ...
} else if (...) {
    ...
} else {
    ...
}
```

如果控制语句分行，则左大括号独占一行且不缩进。例如：

```cpp
if (a_long_expression
    && another_long_expression
    || a_third_long_expression)
{
    ...
}
```

#### 三元运算符

如果三元运算符分行，则在三元运算符前有一个换行符，并使用块缩进。运算符和运算数之间应有一个空格。

```cpp
int y = x ? 0 : 1;

// 必须拆为多行的一个例子。
int y = something_very_long
    ? not_small
    : also_not_small;
```

### Switch

`case` 语句和 `case` 语句后面的块都使用一个块缩进，`default` 后不要加 `break`：

```cpp
switch (foo) {
    case a_very_long_expression:
        // ...
        break;
    case another_expression:
    case yet_another_expression:
        // ...
        break;
    default:
        // ...
}
```

### 可结合的表达式

一个函数调用如果只有一个参数，且这个参数被格式化为多行，那么较外面的调用可以被当作单行调用来格式化。此类结合行为可以被用于任何相似的表达式（拥有多行、块缩进的子表达式列表，且被小括号括起来，例如宏和列表初始化的结构体）。例如，

```cpp
foo(bar(
    an_expr,
    another_expr
));

auto x = foo(Bar {
    whatever,
});

foo([&param]() {
    action();
    return foo(param);
});
```

这种结合规则适用于多层调用。然而格式化工具可能会限制嵌套的深度。

只有当多行的子表达式是一个 lambda 表达式的时候，这个结合规则才可能被用于拥有多个参数的函数调用，前提是所有参数和 lambda 表达式的首行都在第一行，lambda 表达式是最后一个参数且只有一个捕获变量。

```cpp
foo(first_arg, x, [param]() {
    action();
    return foo(param);
});
```

### 基于 range 的 for 循环

在基于 range 的 for 循环中，冒号后面应有一个空格。冒号前面没有空格。

```cpp
for(auto v: values) {}
```

### 十六进制字面量

十六进制字面量可以使用大写或小写字母，但是在同一表达式中不要混用大小写。在同一工程中应该使用同样的大小写，但是我们对此不进行建议。格式化工具应该提供转换混用大小写的字面量的选项，以及转换所有字面量为大写或小写的选项。
