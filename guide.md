# C++ 代码风格指南

## 使用风格化工具的动机？🤔

格式化代码其实是一个机械性的任务 🤖，但是人工实现又非常耗精力。
程序员只要使用自动格式化工具就可以从这个任务中释放，专注于更重要的事情。

此外，通过坚持既定的风格指南（就比如这个 😭），
程序员不需要制定特别的风格规则，也不需要与其他程序员讨论应该使用什么风格规则，
节省时间、精力和交流成本。

人类要理解代码，往往是通过类似于模式匹配的过程。如果一份 C++ 代码拥有统一的风格，
理解一个新项目的代码只需要更少的脑力，从而降低新开发者的进入门槛。

因此，使用格式化工具 (例如 Clang-Format) 能提高生产力。
如果团队坚持使用一种风格，则会有更大的好处，
想要达成此目标并不难，只要使用团队 `.clang-format, .clang-tidy` 的默认设置就可以了。

## 格式化约定

### 缩进和行宽

* 使用空格，而不是 Tab。
* 每级缩进使用 4 个空格（也就是说在纯字符串和注释之外的缩进都是 4 的倍数）
* 行宽最大为 100

### 空行

不同的语句之间要么不空行，要么空一行。E.g,

```cpp
fn foo() {
    let x = ...;

    let y = ...;
    let z = ...;
}

fn bar() {}
fn baz() {}
```

### [Module-level items](items.md)
### [Statements](statements.md)
### [Expressions](expressions.md)
### [Types](types.md)


### 注释

格式化工具可能会跳过以下部分要求。

相较于块注释 (`/* ... */`) 更倾向于行注释 (`//`)。

当使用行注释时，开头标记后应该有一个空格。

使用行内块注释时，开符号后和闭符号前均有一个空格。多行块注释，开符号后和闭符号前均有一个新行。

相比其他，更倾向于行尾评论。行尾平均之前带有 1 个空格。行内块注释周围的空格
应该把注释块当作关键字一样处理。尾随注释和多行注释任意一行的末尾不应有尾随空格。

```cpp
// 条目上方的注释
struct Foo { ... };

fn foo() {} // 条目尾随注释

pub fn foo(/* 参数前的注释 */ x: T) {...}
```

注释应是完整的句子，行内块注释则不用。

纯注释行的注释宽度不大于 80，且算上缩进总宽度不超过 100.

```cpp
// This comment goes up to the ................................. 80 char margin.

{
    // This comment is .............................................. 80 chars wide.
}

{
    {
        {
            {
                {
                    {
                        // This comment is limited by the ......................... 100 char margin.
                    }
                }
            }
        }
    }
}
```

#### 注释文档

相比块注释 (`/** ... */`) 更倾向于行注释 (`///`)。

---

Prefer outer doc comments (`///` or `/** ... */`), only use inner doc comments
(`//!` and `/*! ... */`) to write module-level or crate-level documentation.


更喜欢外部文档注释（`///` 或 `/**... */`），只使用内部文档注释
(`//!` 和 `/*! ... */`) 编写模块级或 crate 级文档。

Doc comments should come before attributes.

文档注释应该在属性之前。

### Attributes

Put each attribute on its own line, indented to the level of the item.
In the case of inner attributes (`#!`), indent it to the level of the inside of
the item. Prefer outer attributes, where possible.

For attributes with argument lists, format like functions.

```cpp
#[repr(C)]
#[foo(foo, bar)]
struct CRepr {
    #![repr(C)]
    x: f32,
    y: f32,
}
```

For attributes with an equal sign, there should be a single space before and
after the `=`, e.g., `#[foo = 42]`.

There must only be a single `derive` attribute. Note for tool authors: if
combining multiple `derive` attributes into a single attribute, the ordering of
the derived names should be preserved. E.g., `#[derive(bar)] #[derive(foo)]
struct Baz;` should be formatted to `#[derive(bar, foo)] struct Baz;`.

### 属性

将每个属性放在自己的行中，缩进到项目的级别。
在内部属性 (`#!`) 的情况下，将其缩进到内部的级别
该项目。尽可能使用外部属性。

对于带有参数列表的属性，格式类似于函数。

```cpp
#[代表(C)]
#[foo(foo, bar)]
结构 CRepr {
    #![代表(C)]
    x: f32,
    是：f32，
}
```

对于带等号的属性，和之前应该有一个空格
在 `=` 之后，例如 `#[foo = 42]`。
必须只有一个 `derive` 属性。工具作者注意事项：如果
将多个“派生”属性组合成一个属性，顺序
应保留衍生名称。例如，`#[derive(bar)] #[derive(foo)]
struct Baz;` 的格式应为 `#[derive(bar, foo)] struct Baz;`。

### *small* items

In many places in this guide we specify that a formatter may format an item
differently if it is *small*, for example struct literals:

```cpp
// Normal formatting
Foo {
    f1: an_expression,
    f2: another_expression(),
}

// *small* formatting
Foo { f1, f2 }
```

We leave it to individual tools to decide on exactly what *small* means. In
particular, tools are free to use different definitions in different
circumstances.

Some suitable heuristics are the size of the item (in characters) or the
complexity of an item (for example, that all components must be simple names,
not more complex sub-expressions). For more discussion on suitable heuristics,
see [this issue](https://github.com/cpp-lang-nursery/fmt-rfcs/issues/47).

Tools should give the user an option to ignore such heuristics and always use
the normal formatting.


## [Non-formatting conventions](advice.md)

## [Cargo.toml conventions](cargo.md)

## [Principles used for deciding these guidelines](principles.md)
