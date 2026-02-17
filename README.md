*This project has been created as part of the 42 curriculum by jericard.*

# push_swap

## Description

push_swap is a sorting algorithm project where the goal is to sort a stack of integers using a limited set of operations, with the lowest possible number of moves. The program receives a list of integers as arguments and outputs a sequence of instructions that sorts them in ascending order.

The project uses two stacks (`a` and `b`) and a restricted set of operations:

| Operation | Description |
|-----------|-------------|
| `sa` / `sb` / `ss` | Swap the first two elements of stack a / b / both |
| `ra` / `rb` / `rr` | Rotate stack a / b / both (top element goes to bottom) |
| `rra` / `rrb` / `rrr` | Reverse rotate stack a / b / both (bottom element goes to top) |
| `pa` / `pb` | Push top element from b to a / from a to b |

### Algorithm

The sorting strategy is based on the **Turkish Sort algorithm** (cost-based approach):

1. Push all elements from stack `a` to stack `b`, except the last 5, choosing the cheapest element to move each time based on the combined rotation cost of both stacks.
2. Sort the remaining 5 elements in `a` using a dedicated `sort_5` routine: push the 2 smallest to `b`, sort the 3 remaining with `order_3`, then push the 2 back.
3. Rotate stack `b` so that the maximum is at the top (descending order).
4. Push all elements from `b` back to `a`, finding the correct insertion position for each.
5. Final rotation of `a` to place the minimum at the top.

The cost optimization uses combined operations (`rr`, `rrr`) when both elements need to rotate in the same direction, reducing the total number of moves.

### Improvement: sort_5

The original Turkish Sort approach leaves only 3 elements in stack `a` before pushing back. This implementation was improved by leaving 5 elements instead and sorting them with a dedicated routine. This saves approximately 13-14 operations per sort (two fewer iterations of the expensive main loop), which was critical to consistently stay under the 5500-operation limit for 500 numbers.

## Instructions

### Compilation

```bash
make        # Compiles push_swap
make bonus  # Compiles the checker program
make clean  # Removes object files
make fclean # Removes object files and executables
make re     # Full recompilation
```

### Usage

```bash
./push_swap 3 1 2 5 4
```

The program outputs the list of operations to sort the given numbers. To verify the result:

```bash
ARG="3 1 2 5 4"; ./push_swap $ARG | ./checker $ARG
```

To count the number of operations:

```bash
ARG="3 1 2 5 4"; ./push_swap $ARG | wc -l
```

### Error handling

The program prints `Error` to stderr in the following cases:
- Non-integer arguments
- Arguments exceeding integer limits
- Duplicate numbers

## Resources

### References

- [Push Swap - A journey to find the most efficient sorting algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) - Blog by A. Yigit Ogun, designer of the Turkish Sort algorithm used as the foundation for this project's sorting strategy.

### AI Usage

Claude (Anthropic) was used as a consultation tool during the development of this project for the following purposes:

- **Debugging**: Identification of bugs in the logicto reduce unnecessary operations.
- **Algorithm optimization**: The improvement of leaving 5 elements in stack `a` instead of 3 (sort_5 strategy) was developed with AI assistance to reduce the operation count and consistently meet the 5500-operation limit for 500 numbers.
- **Code efficiency**: General consultation for analyzing the cost calculation functions and identifying areas where operations could be reduced without restructuring the entire codebase.
