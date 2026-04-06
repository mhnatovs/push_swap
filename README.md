# push_swap

Sort a stack of integers using two stacks and a limited set of operations — with as few moves as possible.

---

## Usage

```bash
make
./push_swap 3 1 2 5 4
```

Outputs the list of operations to sort stack `a`.

---

## Operations

| Op | Description |
|---|---|
| `sa` `sb` `ss` | Swap top two elements |
| `pa` `pb` | Push top of one stack to the other |
| `ra` `rb` `rr` | Rotate up |
| `rra` `rrb` `rrr` | Rotate down |

---

## Algorithm

- **≤ 3 elements** — hardcoded logic
- **≤ 5 elements** — small sort
- **larger** — chunk-based sort

---

## Build

```bash
make        # build
make re     # rebuild
make fclean # clean all
```

---

**mhnatovs** — 42 School
