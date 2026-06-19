# `const` in C

`const` is a keyword that indicates a variable's value **cannot be changed after it has been initialized**.

## Reading rule

`const` always applies to the element on its **left**. If there is nothing on the left, it applies to the element on its **right**.

## Common patterns

### `const char *p`
- `const` has nothing on its left → applies to `char` (on the right)
- Meaning: pointer to a **constant char**
- You **cannot** change `*p`, but you **can** change `p` (make it point elsewhere)

### `char *const p`
- `const` has `*` on its left → applies to the pointer
- Meaning: **constant pointer** to a char
- You **can** change `*p`, but you **cannot** change `p` (it must always point to the same address)

### `const char *const p`
- First `const`: nothing on the left → applies to `char`
- Second `const`: `*` on the left → applies to the pointer
- Meaning: **constant pointer to a constant char**
- You **cannot** change either `*p` or `p`

## Quick summary table

| Declaration            | Pointer changeable? | Value changeable? |
|-------------------------|:--------------------:|:--------------------:|
| `char *p`               | ✅ Yes                | ✅ Yes                |
| `const char *p`         | ✅ Yes                | ❌ No                 |
| `char *const p`         | ❌ No                 | ✅ Yes                |
| `const char *const p`   | ❌ No                 | ❌ No                 |

## Tip

Read the declaration **right to left** starting from the variable name — this often makes it easier to parse:

`const char *const p` → `p` is a `const` pointer to a `const` `char`.