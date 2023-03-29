## 表达式
### 块

块状表达式在开花括号 `{` 之后和闭花括号 `}` 之前都应有 newline 符。块前的任何限定符都应与 `{`在同一行，且间隔一个空格。块中的内容应使用块缩进。

```cpp
void block_as_stmt() {
    a_call();

    {
        a_call_inside_a_block();

        // a comment in a block
        return the_value;
    }
}

void block_as_expr() {
    auto foo = [&]() {
        a_call_inside_a_block();

        // a comment in a block
        return the_value;
    }();
}
```

在块中的预处理指令的缩进应和其他表达式一致

```cpp
void block_as_stmt() {
    #ifdef a_definition
    {
        #define another_definition

        // a comment in a block
        #undef another_definition
    }
    #endif
}
```

不要在花括号的同一行中写注释。

空块的写法是 `{}`。

块在同时满足以下条件的情况下可以只占一行：

* 块以 lambda 表达式而非语句的形式出现
* 其中包含单行语句
* 其中不包含注释

单行块状表达式在开花括号前喝闭花括号后都应有一个空格。

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
        // comment
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

如果初始化列表是*小*的，则它可以放在一行。否则，初始化成员应该有自己的块缩进。多行初始化列表的最后一个参数应有尾随逗号。

开花括号 `{` 之前应有一个空格。在单行初始化列表中，开花括号后和闭花括号前需有一个空格。

```cpp
Foo f1 = Foo { 1, 2, 3 };
Foo f2 = Foo {
    field1,
    an_expr,
};
```

### 数组访问

方括号两边不加空格，尽量避免换行。在目标表达式和开括号之间不要空行。
如果下标表达式有多行，应使用块缩进，而且开括号之后和闭括号之前应换行。
不过要避免多行的下标表达式。

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

大方使用括号，不要因为运算符优先级就省略括号（比如，
使用 `(a && b) || (c && d)` 而非 `a && b || c && d`，虽然他们表达的意思一致）。格式化工具不可添加或移除括号。
不要使用括号来表明优先级。

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

不要在函数名和开小括号之间加空格。

不要在参数和其尾随的逗号之间加空格。

在参数前的逗号和参数之间加空格。

调用尽量写成单行的。

#### 单行调用

函数名与开括号，开括号和首个参数，最后一个参数和闭括号之间不要有空格。

```cpp
foo(x, y, z)
```

#### 多行调用

若函数不是*小*的，或者它会超出行宽限制，或者任何参数或参数的调用是多行的，则该调用应格式化为多行。
该情况下，每个参数独占块缩进的单行。开括号后闭括号前应换行。例如，

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

如果宏可以像其他结构一样解析，则像其他结构一样格式化。例如 `FOO(a, b, c)` 可以被
解析为一个函数调用（除了命名风格不同），所以它按照函数调用一样格式化。

### 域和方法调用链

调用链由域访问（`::`）和方法调用（`. 或 ->`）构成。

尽量写在单行内。如果需要写成多行，则所有元素应该独占一行，且以 `.` 作为新行的开头。
每行都应该是块缩进的。例如，

```cpp
int foo = bar
    .baz?
    .qux();
```

如果一个调用链的第一个元素的最后一行加上其缩进小于下一行的缩进，
则只要有足够的空间，就应合并这两行。例如，

```cpp
// use
x.baz
    .qux()
// not
x
    .baz
    .qux()

// use
int foo = x
    .baz?
    .qux();

foo(
    expr1,
    expr2
).baz
    .qux();
```

#### 多行元素

若一个调用链中的某个元素被格式化为多行，则该元素和其后的元素应独占一行。
其前的元素可以写在同一行。例如，

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

将整个调用格式化为多行且每个元素独占一行，
要优于把部分元素放在同一行而其他元素格式化为多行。
例如，

```cpp
// Better
this->pre_comment
    .as_ref()
    .map_or(false, [&](auto comment) { return comment.starts_with("//"); })

// Worse
this->pre_comment.as_ref().map_or(
    false,
    [&](auto comment) { return comment.starts_with("//"); }
)
```

### 控制流表达式

本小节包括 `if`，`for`，`while`，`do-while` 表达式。

关键字、条件表达式和开括号应在同一行。执行语句块应使用[块的格式化](#块)。

如果有 `else` 部分，则 `else` 之前的闭括号，`else`，接下来的条件表达式和开括号
都应在同一行。`else` 前后应有一个空格。例如：

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

If the control line needs to be broken, then prefer to break before the `=` in
`* let` expressions and before `in` in a `for` expression; the following line
should be block indented. If the control line is broken for any reason, then the
opening brace should be on its own line and not indented. Examples:

```cpp
while let Some(foo)
    = a_long_expression
{
    ...
}

for foo
    in a_long_expression
{
    ...
}

if a_long_expression
    && another_long_expression
    || a_third_long_expression
{
    ...
}
```

Where the initial clause is multi-lined and ends with one or more closing
parentheses, square brackets, or braces, and there is nothing else on that line,
and that line is not indented beyond the indent on the first line of the control
flow expression, then the opening brace of the block should be put on the same
line with a preceding space. For example:

```cpp
if !self.config.file_lines().intersects(
    &self.codemap.lookup_line_range(
        stmt.span,
    ),
) {  // Opening brace on same line as initial clause.
    ...
}
```


#### Single line `if else`

Formatters may place an `if else` or `if let else` on a single line if it occurs
in expression context (i.e., is not a standalone statement), it contains a
single `else` clause, and is *small*. For example:

```cpp
let y = if x { 0 } else { 1 };

// Examples that must be multi-line.
let y = if something_very_long {
    not_small
} else {
    also_not_small
};

if x {
    0
} else {
    1
}
```


### Match

Prefer not to line-break inside the discriminant expression. There must always
be a line break after the opening brace and before the closing brace. The match
arms must be block indented once:

```cpp
match foo {
    // arms
}

let x = match foo.bar.baz() {
    // arms
};
```

Use a trailing comma for a match arm if and only if not using a block. 

Never start a match arm pattern with `|`, e.g.,

```cpp
match foo {
    // Don't do this.
    | foo => bar,
    // Or this.
    | a_very_long_pattern
    | another_pattern
    | yet_another_pattern
    | a_forth_pattern => {
        ...
    }
}
```

Prefer


```cpp
match foo {
    foo => bar,
    a_very_long_pattern
    | another_pattern
    | yet_another_pattern
    | a_forth_pattern => {
        ...
    }
}
```

Avoid splitting the left-hand side (before the `=>`) of a match arm where
possible. If the right-hand side of the match arm is kept on the same line,
never use a block (unless the block is empty).

If the right-hand side consists of multiple statements or has line comments or
the start of the line cannot be fit on the same line as the left-hand side, use
a block. A block may also be used in cases where the right-hand side is a macro call expression to prevent issues with expansions containing a trailing semicolon, more details [below](#macro-call-expressions).

The body of a block arm should be block indented once.

Examples:

```cpp
match foo {
    foo => bar,
    a_very_long_patten | another_pattern if an_expression() => {
        no_room_for_this_expression()
    }
    foo => {
        // A comment.
        an_expression()
    }
    foo => {
        let a = statement();
        an_expression()
    }
    bar => {}
    // Trailing comma on last item.
    foo => bar,
}
```

If the body is a single expression with no line comments and not a control flow
expression, then it may be started on the same line as the left-hand side. If
not, then it must be in a block. Example,

```cpp
match foo {
    // A combinable expression.
    foo => a_function_call(another_call(
        argument1,
        argument2,
    )),
    // A non-combinable expression
    bar => {
        a_function_call(
            another_call(
                argument1,
                argument2,
            ),
            another_argument,
        )
    }
}
```

#### Line-breaking

Where it is possible to use a block form on the right-hand side and avoid
breaking the left-hand side, do that. E.g.

```cpp
    // Assuming the following line does done fit in the max width
    a_very_long_pattern | another_pattern => ALongStructName {
        ...
    },
    // Prefer this
    a_very_long_pattern | another_pattern => {
        ALongStructName {
            ...
        }
    }
    // To splitting the pattern.
```

Never break after `=>` without using the block form of the body.

If the left-hand side must be split and there is an `if` clause, break before
the `if` and block indent. In this case, always use a block body and start the
body on a new line:

```cpp
    a_very_long_pattern | another_pattern
        if expr =>
    {
        ...
    }
```

If required to break the pattern, put each clause of the pattern on its own
line with no additional indent, breaking before the `|`. If there is an `if`
clause, then you must use the above form:

```cpp
    a_very_long_pattern
    | another_pattern
    | yet_another_pattern
    | a_forth_pattern => {
        ...
    }
    a_very_long_pattern
    | another_pattern
    | yet_another_pattern
    | a_forth_pattern
        if expr =>
    {
        ...
    }
```

If the pattern is multi-line, and the last line is less wide than the indent, do
not put the `if` clause on a newline. E.g.,

```cpp
    Token::Dimension {
         value,
         ref unit,
         ..
    } if num_context.is_ok(context.parsing_mode, value) => {
        ...
    }
```

If every clause in a pattern is *small*, but does not fit on one line, then the
pattern may be formatted across multiple lines with as many clauses per line as
possible. Again break before a `|`:

```cpp
    foo | bar | baz
    | qux => {
        ...
    }
```

We define a pattern clause to be *small* if it matches the following grammar:

```
[small, ntp]:
    - single token
    - `&[single-line, ntp]`

[small]:
    - `[small, ntp]`
    - unary tuple constructor `([small, ntp])`
    - `&[small]`
```

E.g., `&&Some(foo)` matches, `Foo(4, Bar)` does not.

#### Macro call expressions
When the right-hand side of a match arm contains a macro call expression, it may be necessary to use a block to prevent issues in expansion.

In some cases the right-hand side may be placed on the same line as the left-hand side. E.g.,

```cpp
macro_rules! expr {
    () => {
        true
    };
}

fn main() {
    let _val: bool = match true {
        true => expr!(),
        false => false,
    };
}
```

However, in other cases it is necessary to use a block to prevent issues in macro expansion, such as with trailing semicolons.

```cpp
macro_rules! stmt {
    () => {
        true;
    };
}

fn main() {
    match true {
        true => {
            stmt!()
        }
        false => {}
    }
}
```

Note that at the time of this writing [cppc ignores these trailing semicolons](https://github.com/cpp-lang/cpp/issues/33953), but this guidance is provided in case that changes.

### Combinable expressions

Where a function call has a single argument, and that argument is formatted
across multiple-lines, the outer call may be formatted as if it were a
single-line call. The same combining behaviour may be applied to any similar
expressions which have multi-line, block-indented lists of sub-expressions
delimited by parentheses (e.g., macros or tuple struct literals). E.g.,

```cpp
foo(bar(
    an_expr,
    another_expr,
))

let x = foo(Bar {
    field: whatever,
});

foo(|param| {
    action();
    foo(param)
})
```

Such behaviour should extend recursively; however, tools may choose to limit the
depth of nesting.

Only where the multi-line sub-expression is a closure with an explicit block,
this combining behaviour may be used where there are other arguments, as long as
all the arguments and the first line of the closure fit on the first line, the
closure is the last argument, and there is only one closure argument:

```cpp
foo(first_arg, x, |param| {
    action();
    foo(param)
})
```


### Ranges

Do not put spaces in ranges, e.g., `0..10`, `x..=y`, `..x.len()`, `foo..`.

When writing a range with both upper and lower bounds, if the line must be
broken, break before the range operator and block indent the second line:

```cpp
a_long_expression
    ..another_long_expression
```

For the sake of indicating precedence, we recommend that if either bound is a
compound expression, then use parentheses around it, e.g., `..(x + 1)`,
`(x.f)..(x.f.len())`, or `0..(x - 10)`.


### Hexadecimal literals

Hexadecimal literals may use upper- or lower-case letters, but they must not be
mixed within the same literal. Projects should use the same case for all
literals, but we do not make a recommendation for either lower- or upper-case.
Tools should have an option to convert mixed case literals to upper-case, and
may have an option to convert all literals to either lower- or upper-case.


## Patterns

Patterns should be formatted like their corresponding expressions. See the
section on `match` for additional formatting for patterns in match arms.
