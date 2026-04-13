# AVL Trees & Rotations — A Complete Beginner's Guide

> **For:** 1st Year B.Tech CSE students who already know basic data structures (arrays, linked lists, stacks, queues, and **Binary Search Trees**).

---

## Table of Contents

1. [The Problem — Why Do We Even Need AVL Trees?](#1-the-problem--why-do-we-even-need-avl-trees)
2. [What Is an AVL Tree?](#2-what-is-an-avl-tree)
3. [Key Vocabulary](#3-key-vocabulary)
4. [Balance Factor — The Heart of AVL](#4-balance-factor--the-heart-of-avl)
5. [The 4 Types of Rotations](#5-the-4-types-of-rotations)
   - [5.1 Left-Left (LL) — Right Rotation](#51-left-left-ll--right-rotation)
   - [5.2 Right-Right (RR) — Left Rotation](#52-right-right-rr--left-rotation)
   - [5.3 Left-Right (LR) — Left then Right Rotation](#53-left-right-lr--left-then-right-rotation)
   - [5.4 Right-Left (RL) — Right then Left Rotation](#54-right-left-rl--right-then-left-rotation)
6. [Quick Cheat Sheet — How to Pick the Right Rotation](#6-quick-cheat-sheet--how-to-pick-the-right-rotation)
7. [Full Worked Example — Building an AVL Tree Step by Step](#7-full-worked-example--building-an-avl-tree-step-by-step)
8. [Time Complexity Comparison](#8-time-complexity-comparison)
9. [Summary & Key Takeaways](#9-summary--key-takeaways)

---

## 1. The Problem — Why Do We Even Need AVL Trees?

### First, remember BST (Binary Search Tree)

A BST gives us fast search — we go left if the value is smaller, right if it's bigger. **Ideally**, this takes **O(log n)** time.

But here's the catch...

### The Worst Case of BST

Insert these values **in order**: `10, 20, 30, 40, 50`

```
    10
      \
       20
         \
          30
            \
             40
               \
                50
```

**This is still a valid BST!** But look — it's basically a linked list. Searching for `50` takes **5 steps** (O(n)), not O(log n).

### The Real-World Analogy

Imagine a library where all books are on one single long shelf, one after another. To find the last book, you walk past every single book. That's terrible!

Now imagine the books are arranged in a **balanced tree-like rack** — you can always eliminate half the books with each decision. That's what an AVL tree does.

> **Bottom line:** A BST can become **skewed** (lopsided), making it as slow as a linked list. AVL trees **prevent this** by keeping the tree balanced after every insertion and deletion.

---

## 2. What Is an AVL Tree?

**AVL Tree** = A self-balancing Binary Search Tree.

- Invented in **1962** by **A**delson-**V**elsky and **L**andis (hence "AVL").
- It follows all BST rules (left < root < right).
- **Extra rule:** For **every** node, the height difference between its left and right subtrees is at most **1**.

```
        30                  30
       /  \                /
      20   40             20         ← BST: valid
     /                   /               AVL: INVALID (skewed)
    10                  10
                       /
                      5

  ✅ AVL Tree         ❌ NOT an AVL Tree
  (balanced)          (left side too heavy)
```

---

## 3. Key Vocabulary

| Term | Meaning |
|------|---------|
| **Height of a node** | Number of edges on the longest path from that node down to a leaf. A leaf has height **0**. An empty (NULL) child has height **-1**. |
| **Balance Factor (BF)** | `Height(left subtree) - Height(right subtree)` |
| **Balanced** | Balance factor is **-1, 0, or +1** |
| **Unbalanced** | Balance factor is **< -1** or **> +1** (i.e., ±2 or more) |
| **Rotation** | A local tree restructuring operation that restores balance |

---

## 4. Balance Factor — The Heart of AVL

For every node:

```
Balance Factor = Height(Left Subtree) - Height(Right Subtree)
```

### Example: Computing Balance Factors

```
            30 [BF = 1]
           /  \
   [BF=0] 20   40 [BF = 0]
          /
  [BF=0] 10
```

Let's calculate step by step:
- Node `10`: No children → Left height = -1, Right height = -1 → BF = -1 - (-1) = **0** ✅
- Node `40`: No children → BF = **0** ✅
- Node `20`: Left child (10) has height 0, No right child (height -1) → BF = 0 - (-1) = **1** ✅
- Node `30`: Left subtree height = 1, Right subtree height = 0 → BF = 1 - 0 = **1** ✅

**All nodes have BF ∈ {-1, 0, +1}**, so this is a valid AVL tree!

### When Does It Break?

If we now insert `5`:

```
              30 [BF = 2] ⚠️ UNBALANCED!
             /  \
     [BF=1] 20   40 [BF = 0]
            /
    [BF=1] 10
           /
   [BF=0] 5
```

- Node `30` now has BF = **2** → **VIOLATION!**
- We need a **rotation** to fix this.

---

## 5. The 4 Types of Rotations

When a node becomes unbalanced (BF = +2 or -2), we identify the **pattern** of imbalance and apply the correct rotation.

There are exactly **4 cases**:

| Case | Imbalance Pattern | Fix |
|------|-------------------|-----|
| **LL** | Inserted into the **Left** subtree of the **Left** child | Single **Right** Rotation |
| **RR** | Inserted into the **Right** subtree of the **Right** child | Single **Left** Rotation |
| **LR** | Inserted into the **Right** subtree of the **Left** child | **Left** Rotation on child, then **Right** Rotation on node |
| **RL** | Inserted into the **Left** subtree of the **Right** child | **Right** Rotation on child, then **Left** Rotation on node |

> **Naming convention:** The case name (LL, RR, LR, RL) tells you the **path from the unbalanced node** to the newly inserted node.

---

### 5.1 Left-Left (LL) — Right Rotation

**When:** The problem is in the **Left** child's **Left** subtree.

**Real-life analogy:** A tree leaning too much to the left — you "pull" the middle node up to straighten it.

#### Example: Insert 5, 10, 15 and then insert 3, then insert 1

Let's just look at the moment it breaks. Say we have:

```
  BEFORE (Unbalanced):               AFTER (Right Rotation on 30):

        30  [BF=2]                         20
       /  \                               /  \
      20   35                            10    30
     /  \                               /    /  \
    10   25                             5    25   35
   /
  5
```

#### How Right Rotation Works (step by step):

Starting tree is unbalanced at node `30`:

```
        30          ← unbalanced node (BF = 2)
       /  \
      20   35       ← left child = 20
     /  \
    10   25         ← 25 is the "orphan" we need to handle
   /
  5
```

**Steps:**
1. **Identify:** Unbalanced node = `30`, its left child = `20`
2. **Lift `20` up** to take `30`'s place
3. **`30` becomes the right child** of `20`
4. **`25` (the right subtree of `20`)** becomes the **left child of `30`** (it was between 20 and 30, so it still belongs there by BST rules!)

```
  Result:
          20            ← new root of this subtree
         /  \
        10   30
       /    /  \
      5    25   35
```

**Check:** All BST properties maintained ✅ All BFs are -1, 0, or +1 ✅

#### Simple 3-Node LL Example:

```
  Insert: 30, 20, 10

      30  [BF=2]          20
     /          →         /  \
    20                   10   30
   /
  10

  Right Rotation on 30
```

---

### 5.2 Right-Right (RR) — Left Rotation

**When:** The problem is in the **Right** child's **Right** subtree.

**This is the exact mirror of LL.**

#### Simple 3-Node RR Example:

```
  Insert: 10, 20, 30

  10  [BF=-2]              20
    \            →         /  \
     20                   10   30
       \
        30

  Left Rotation on 10
```

#### Bigger Example:

```
  BEFORE (Unbalanced at 10):          AFTER (Left Rotation on 10):

     10  [BF=-2]                          20
    /  \                                 /  \
   5    20                              10    30
       /  \                            /  \     \
      15   30                         5   15    35
             \
             35
```

**Steps:**
1. **Identify:** Unbalanced node = `10`, its right child = `20`
2. **Lift `20` up** to take `10`'s place
3. **`10` becomes the left child** of `20`
4. **`15` (the left subtree of `20`)** becomes the **right child of `10`**

```
  Result:
          20
         /  \
        10   30
       /  \    \
      5   15   35
```

**Check:** BST order: 5 < 10 < 15 < 20 < 30 < 35 ✅

---

### 5.3 Left-Right (LR) — Left then Right Rotation

**When:** The problem is in the **Left** child's **Right** subtree.

This is a **double rotation** — one rotation alone won't fix it.

**Real-life analogy:** Imagine a bent arm (zig-zag shape). You can't straighten it with one move — you first straighten the bend, then straighten the whole thing.

#### Simple 3-Node LR Example:

```
  Insert: 30, 10, 20

       30  [BF=2]
      /
     10  [BF=-1]       ← Left child, but problem is on its RIGHT
       \
        20              ← This creates a "zig-zag" pattern
```

**Why single rotation won't work:**
If we just did a right rotation on 30:
```
     10
       \
        30
       /
      20
```
Still not balanced! The zig-zag remains.

**The fix — Two rotations:**

**Step 1: Left Rotation on the LEFT CHILD (10)**
```
       30                    30
      /                     /
     10          →         20
       \                  /
        20               10
```

Now it's an LL pattern!

**Step 2: Right Rotation on the UNBALANCED NODE (30)**
```
       30                    20
      /          →          /  \
     20                    10   30
    /
   10
```

**Final Result: Balanced!** ✅

#### Bigger LR Example:

```
  BEFORE:                      Step 1: Left Rotate on 10     Step 2: Right Rotate on 30

       30 [BF=2]                      30                           20
      /  \                           /  \                         /  \
     10   35                        20   35                      10   30
    /  \                           /                            /   /  \
   5    20                        10                           5   25   35
       /                         /  \
      15                        5   15

  Wait — where did 15 go?

  In Step 1 (Left Rotate on 10):
  - 20 takes 10's place
  - 10 becomes left child of 20
  - 15 (left child of 20) → becomes right child of 10

       30                           20
      /  \                         /  \
     20   35                      10   30
    /  \                         / \   / \
   10  25                       5  15 25  35
  / \
 5  15

  Step 2 (Right Rotate on 30):
  - 20 takes 30's place
  - 30 becomes right child of 20
  - 25 (right child of 20) → becomes left child of 30
```

---

### 5.4 Right-Left (RL) — Right then Left Rotation

**When:** The problem is in the **Right** child's **Left** subtree.

**This is the exact mirror of LR.**

#### Simple 3-Node RL Example:

```
  Insert: 10, 30, 20

  10  [BF=-2]
    \
     30  [BF=1]         ← Right child, but problem is on its LEFT
    /
   20                   ← Zig-zag pattern again
```

**Step 1: Right Rotation on the RIGHT CHILD (30)**
```
  10                      10
    \                       \
     30        →             20
    /                          \
   20                           30
```

Now it's an RR pattern!

**Step 2: Left Rotation on the UNBALANCED NODE (10)**
```
  10                          20
    \            →           /  \
     20                     10   30
       \
        30
```

**Final Result: Balanced!** ✅

#### Bigger RL Example:

```
  BEFORE:                    Step 1: Right Rotate on 40     Step 2: Left Rotate on 10

     10 [BF=-2]                     10                             25
    /  \                           /  \                           /  \
   5    40                        5    25                        10   40
       /  \                           /  \                     /  \    \
      25   45                        20   40                  5   20   45
     /                                      \
    20                                      45

  In Step 1 (Right Rotate on 40):
  - 25 takes 40's place
  - 40 becomes right child of 25
  - (right child of 25, if any) → becomes left child of 40

  In Step 2 (Left Rotate on 10):
  - 25 takes 10's place
  - 10 becomes left child of 25
  - 20 (left child of 25) → becomes right child of 10

  Final:
          25
         /  \
        10   40
       / \     \
      5  20    45
```

---

## 6. Quick Cheat Sheet — How to Pick the Right Rotation

When a node becomes unbalanced (BF = +2 or -2), trace the path from the **unbalanced node** toward the **newly inserted node**:

```
  ┌──────────────────────────────────────────────────────────┐
  │                                                          │
  │   BF of unbalanced node = +2                             │
  │   (Left-heavy)                                           │
  │   ├── BF of LEFT child = +1 or 0 → LL → Right Rotate    │
  │   └── BF of LEFT child = -1      → LR → Left-Right      │
  │                                                          │
  │   BF of unbalanced node = -2                             │
  │   (Right-heavy)                                          │
  │   ├── BF of RIGHT child = -1 or 0 → RR → Left Rotate    │
  │   └── BF of RIGHT child = +1      → RL → Right-Left     │
  │                                                          │
  └──────────────────────────────────────────────────────────┘
```

### Memory Trick 🧠

| If the path is... | Shape | Fix |
|---|---|---|
| **Left → Left** (straight line \\) | Straight | **One** rotation (Right) |
| **Right → Right** (straight line /) | Straight | **One** rotation (Left) |
| **Left → Right** (zig-zag <) | Bent | **Two** rotations (Left then Right) |
| **Right → Left** (zig-zag >) | Bent | **Two** rotations (Right then Left) |

> **Straight path = Single rotation. Zig-zag path = Double rotation.**

---

## 7. Full Worked Example — Building an AVL Tree Step by Step

Let's insert these values one by one: **40, 20, 60, 10, 30, 50, 70, 5, 25, 35**

### Insert 40
```
  40 [BF=0]              ✅ Balanced
```

### Insert 20
```
    40 [BF=1]
   /
  20 [BF=0]              ✅ Balanced
```

### Insert 60
```
      40 [BF=0]
     /  \
    20   60               ✅ Balanced
```

### Insert 10
```
        40 [BF=1]
       /  \
      20   60
     /
    10                    ✅ Balanced (BF of 40 = 1, BF of 20 = 1)
```

### Insert 30
```
        40 [BF=1]
       /  \
      20   60
     /  \
    10  30                ✅ Balanced (BF of 20 = 0, BF of 40 = 1)
```

### Insert 50
```
        40 [BF=0]
       /  \
      20   60
     / \   /
    10 30 50              ✅ Balanced
```

### Insert 70
```
        40 [BF=0]
       /  \
      20     60
     / \    /  \
    10  30 50  70         ✅ Balanced — a perfect tree!
```

### Insert 5
```
          40 [BF=1]
         /  \
        20     60
       / \    /  \
      10  30 50  70
     /
    5                     ✅ Balanced (BF of 10 = 1, BF of 20 = 1, BF of 40 = 1)
```

### Insert 25
```
          40 [BF=1]
         /  \
        20       60
       / \      /  \
      10  30   50  70
     /   /
    5   25                ✅ Balanced (BF of 30 = 1, BF of 20 = 0, BF of 40 = 1)
```

### Insert 35 ⚠️

```
            40 [BF=2] ⚠️ UNBALANCED!
           /  \
          20       60
         / \      /  \
        10  30   50  70
       /   / \
      5   25  35

  BF of node 40 = 2 (Left subtree height=3, Right subtree height=1)
```

**Identify the case:**
- Unbalanced node: `40` (BF = +2) → Left-heavy
- Left child: `20` (BF = -1) → its right subtree is heavier

**Path: Left then Right → LR Case!**

**Step 1: Left Rotate on `20`**
```
            40
           /  \
          30       60
         / \      /  \
        20  35   50  70
       / \
      10  25
     /
    5
```

**Step 2: Right Rotate on `40`**
```
            30
           /  \
          20     40
         / \    /  \
        10  25 35   60
       /           /  \
      5           50  70
```

**Final tree after inserting all 10 values:**
```
            30
           /  \
          20     40
         / \    /  \
        10  25 35   60
       /           /  \
      5           50  70
```

**Verify BST order:** 5 < 10 < 20 < 25 < 30 < 35 < 40 < 50 < 60 < 70 ✅

**Verify balance:** Every node has BF ∈ {-1, 0, +1} ✅

---

## 8. Time Complexity Comparison

| Operation | BST (Worst Case) | BST (Average) | AVL Tree (All Cases) |
|-----------|:-:|:-:|:-:|
| **Search** | O(n) | O(log n) | **O(log n)** |
| **Insert** | O(n) | O(log n) | **O(log n)** |
| **Delete** | O(n) | O(log n) | **O(log n)** |
| **Rotation cost** | — | — | O(1) per rotation |

> AVL trees **guarantee** O(log n) because the height is always kept at approximately log₂(n).

### Space Complexity

- AVL tree: **O(n)** — same as BST, but each node stores one extra integer (the height or balance factor).

---

## 9. Summary & Key Takeaways

### Why AVL Trees Exist
- BSTs can become **skewed** (like a linked list) → O(n) operations.
- AVL trees **self-balance** after every insert/delete → **guaranteed O(log n)**.

### What Makes AVL Special
- Every node maintains a **balance factor** (BF = left height − right height).
- BF must be **-1, 0, or +1** for every node.
- If violated → **rotate** to fix.

### The 4 Rotations — Summary

```
  LL (Left-Left):   Straight left path   → Single Right Rotation
  RR (Right-Right): Straight right path  → Single Left Rotation
  LR (Left-Right):  Zig-zag (left-right) → Left Rotate child, then Right Rotate node
  RL (Right-Left):  Zig-zag (right-left) → Right Rotate child, then Left Rotate node
```

### Golden Rules
1. **Always check balance factor** after every insertion/deletion, going bottom-up.
2. **Straight imbalance** (LL or RR) → **1 rotation** fixes it.
3. **Zig-zag imbalance** (LR or RL) → **2 rotations** (first straighten, then fix).
4. **Orphan subtrees** get re-attached to maintain BST ordering.
5. After rotation, the tree is balanced — **no cascading rotations needed for insertion** (at most one rotation point).

---

### What to Practice Next

1. **Draw it out** — Take random numbers, insert them one by one, and draw the AVL tree at each step.
2. **Spot the case** — Given an unbalanced tree, identify if it's LL, RR, LR, or RL.
3. **Code it** — Implement AVL insert in C/C++ (the rotation logic maps directly to pointer manipulation).
4. **Deletion** — AVL deletion is similar but may require multiple rotations (slightly more complex).

---

> _"The key to mastering AVL trees is mastering the 4 rotations. Once you can do them on paper without thinking, the code writes itself."_
