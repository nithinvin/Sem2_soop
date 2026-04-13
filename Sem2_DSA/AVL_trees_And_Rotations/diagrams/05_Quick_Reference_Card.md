# AVL Rotation Quick Reference Card

## Decision Flowchart

```
  Node is unbalanced
         │
         ▼
  ┌──── BF = ? ────┐
  │                 │
  BF = +2           BF = -2
  (LEFT heavy)      (RIGHT heavy)
  │                 │
  ▼                 ▼
  Check LEFT        Check RIGHT
  child's BF        child's BF
  │                 │
  ├─ +1 or 0        ├─ -1 or 0
  │  → LL Case      │  → RR Case
  │  → Right        │  → Left
  │    Rotation     │    Rotation
  │                 │
  └─ -1             └─ +1
     → LR Case         → RL Case
     → Left-Right       → Right-Left
       Rotation           Rotation
```

## All 4 Cases at a Glance

```
  LL:  Z          Y          RR:      Z            Y
      / \   →   / \              / \    →      / \
     Y  T4    X    Z           T1   Y        Z    X
    / \      /\   /\               / \      /\   /\
   X  T3   T1 T2 T3 T4          T2   X   T1 T2 T3 T4
  /\                                 /\
T1 T2                              T3 T4

  LR:    Z              Y         RL:  Z              Y
        / \    →      /   \           / \    →      /   \
       X  T4        X      Z       T1   X        Z      X
      / \          /\     /\            / \      /\     /\
    T1   Y       T1 T2 T3 T4          Y  T4   T1 T2 T3 T4
        / \                           / \
      T2  T3                        T2  T3
```

## Pattern Recognition Summary

| Unbalanced Node BF | Child BF | Case | Path Shape | Rotation(s) |
|:---:|:---:|:---:|:---:|---|
| **+2** | **+1 or 0** | LL | `\` straight | Right Rotate |
| **-2** | **-1 or 0** | RR | `/` straight | Left Rotate |
| **+2** | **-1** | LR | `<` zig-zag | Left on child → Right on node |
| **-2** | **+1** | RL | `>` zig-zag | Right on child → Left on node |

## Remember

- **Straight = 1 rotation**
- **Zig-zag = 2 rotations** (first straighten the bend, then fix)
- In double rotations, the **grandchild** always becomes the new root
- **Orphan subtrees** always get re-attached to maintain BST order
