# cpp code formatting RFCs

This repository exists to decide on a code style for cpp code, to be enforced
by the cppfmt tool. Accepted RFCs live in the `text` directory and form a
specification for formatting tools.

The [cpp style guide](guide/guide.md) in this repository documents this style,
including examples.

## The formatting RFC process

See [RFC 1607](https://github.com/cpp-lang/rfcs/pull/1607) for more details.
Where this process is under-specified, see the process for [cpp RFCs](https://github.com/cpp-lang/rfcs).

* Open a GitHub issue on the fmt-rfcs repo for discussion. This discussion should
  define the style in as much detail as possible using rules and examples.
  - Search for existing issues and RFCs that may have already covered the topic.
    To discourage endless bikeshedding, the style team will close new discussions
    on old topics unless they provide fresh information (such as feedback based
    on having an implementation) or alternatives that were not previously
    considered.
* When discussion has reached a fixed point, the issue will be put into a final
  comment period (FCP).
* Reach consensus on the issue.
* Implement the style in cppfmt (behind an option if it is not the current
  default).
* Submit a PR to fmt-rfcs updating the style guide with the new style and the
  examples using the newly updated cppfmt. The PR should include the default
  values for options to enforce the guideline, and which non-default options
  should be kept.
* If discussion is brief and the PR closely matches the original issue, it will
  be merged. If there are changes, then we will have an FCP for the PR too.
* Implementation in cppfmt can then be finished (including any changes due to
  discussion of the PR), and default options are set.


### Scope of the process

This process is specifically limited to formatting style guidelines which can be
enforced by cppfmt with its current architecture. Guidelines that cannot be
enforced by cppfmt without a large amount of work are out of scope, even if
they only pertain to formatting.
