# Regular Language

**Regular langauges are sets of string patterns, regardless of meaning. These patterns are form-based, matchable using finite rules, and don't require nested memory structures**.
 * Regular language is something comprised of some pattern.
 * A **regular language** is defined by **patterns** that can be recognized using **finite memory** *(no stack, no tape - just a finte state matchine). Like: 'aaab', 'cccdab', 'man, 'can', etc.*.
 * These are all examples of **strings**, and a regular language can be defined to **accept** certain strings and **reject** others -based solely on patterns like:
   * Fixed sequences *(man)*
   * Repetition *(a\*)*
   * Alternatives *(cat|dog)*
   * Concatenation *(abc123)*
   * Simple anchors *(^word$)*
 * **Meaning is irrelevant** to regular languages. They are all about **form**, not **ssemantics**.

## Key Concept: Regular Languages = Pattern Sets
We can think of a regular languages as a **set of strings** that match a particular **pattern**.
Example:
```txt
Language L = all strings over {a, b} where a appears exactly 3 times
```
That would inclue:
 * *aaab*
 * *abaab*
 * *babaab*
 * but not *aaaa*

## Formal Definition (Plain English)
A **regular language** is any language *(set of strings)* that can be defined using:
 * **Finite State Machines (FSMs)** - Deterministic (DFA) or Nondeterministic (NFA)
 * **Regular Expressions** - Using `*`, `+`, `?`, `|`, grouping, character classes
 * **Regular Grammars** - right-linear or left-linear rules

## Real-life Examples (Regular Languages)
|Regular Pattern|Matches|Notes|
|---|---|---|
|`a*`|`""`, `a`, `aa`, `aaa`|Zero or more `a`S|

