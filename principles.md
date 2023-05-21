## 非常重要的指南

块缩进比对齐缩进更好。例如：

```cpp
// 块缩进
a_function_call(
    foo,
    bar
);

// 对齐缩进
a_function_call(foo,
                bar);
```

这样能减小代码修改时的 diff（例如 `a_function_call` 在上例中被重命名）而且能防止右飘。

列表元素应尾随逗号，这样移动代码（比如：复制粘贴）更容易，而且减小代码修改造成的 diff。
