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
| **Height of a node** | Number of **edges** on the longest path going **downward** from that node to a leaf node. |
| **Balance Factor (BF)** | `Height(Left Subtree) - Height(Right Subtree)` for a given node |
| **Balanced node** | Balance factor is **-1, 0, or +1** |
| **Unbalanced node** | Balance factor is **≤ -2** or **≥ +2** |
| **Rotation** | A local restructuring operation that fixes an unbalanced node |

---

## 4. Balance Factor — The Heart of AVL

### Step 1 — Understand HEIGHT first

> **Height of a node** = number of edges on the longest downward path from that node to a leaf.

**Two special rules to memorize:**
- A **leaf node** (no children) has height = **0**
- A **NULL** (empty / non-existent) node has height = **-1**

Why -1 for NULL? Because when a node has only one child, we still need to measure the "empty" side. Saying NULL = -1 makes the formula consistent.

#### Height Examples — Build intuition one level at a time

```
  EXAMPLE A: Single node

        10          height of 10 = 0
                    (it is a leaf — no edges going down)
```

```
  EXAMPLE B: Two levels

        20          height of 20 = 1
       /            (one edge down to 10)
      10            height of 10 = 0  (leaf)
```

```
  EXAMPLE C: Three levels, fully balanced

        30          height of 30 = 2  (longest path: 30→20→10, two edges)
       /  \
      20   40       height of 20 = 1, height of 40 = 0  (40 is a leaf)
     /
    10              height of 10 = 0  (leaf)
```

```
  EXAMPLE D: Three levels, right-only chain

        10          height of 10 = 2
          \         (longest path: 10→20→30, two edges)
           20       height of 20 = 1
             \
              30    height of 30 = 0  (leaf)
```

**Key insight:** Height is always measured going **downward**. Count the number of lines (edges) you cross on the longest path from that node to the bottom.

---

### Step 2 — Understand BALANCE FACTOR

Once you know the heights, the balance factor is straightforward:

```
  Balance Factor (BF) of a node = Height(its Left child) − Height(its Right child)
```

If a child doesn't exist (NULL), use height = **-1**.

**What the sign of BF tells you:**
- BF = **0** → Left and right sides are equally tall
- BF = **+1** → Left side is 1 level taller (OK)
- BF = **-1** → Right side is 1 level taller (OK)
- BF = **+2** → Left side is 2 levels taller → **VIOLATION, fix needed**
- BF = **-2** → Right side is 2 levels taller → **VIOLATION, fix needed**

---

### Step 3 — Worked Examples: Computing Balance Factor

**Always calculate BF from the bottom up** (leaves first, then move upward).

#### Example 1 — Simple 3-node balanced tree

```
        30
       /  \
      20   40
```

| Node | Left child | Left height | Right child | Right height | BF = Left − Right |
|:----:|:----------:|:-----------:|:-----------:|:------------:|:-----------------:|
| 20   | NULL       | **-1**      | NULL        | **-1**       | -1 − (-1) = **0** |
| 40   | NULL       | **-1**      | NULL        | **-1**       | -1 − (-1) = **0** |
| 30   | node 20    | **0**       | node 40     | **0**        | 0 − 0 = **0**     |

All BFs are 0 → **Perfectly balanced** ✅

---

#### Example 2 — Four nodes, slightly left-heavy

```
        30
       /  \
      20   40
     /
    10
```

**Bottom up — start at the leaves:**

| Node | Left child | Left height | Right child | Right height | BF = Left − Right |
|:----:|:----------:|:-----------:|:-----------:|:------------:|:-----------------:|
| 10   | NULL       | **-1**      | NULL        | **-1**       | -1 − (-1) = **0** |
| 40   | NULL       | **-1**      | NULL        | **-1**       | -1 − (-1) = **0** |
| 20   | node 10    | **0**       | NULL        | **-1**       | 0 − (-1) = **+1** |
| 30   | node 20    | **1**       | node 40     | **0**        | 1 − 0 = **+1**    |

All BFs are in {-1, 0, +1} → **Valid AVL tree** ✅

```
        30 [BF=+1]
       /  \
      20   40
  [BF=+1]  [BF=0]
     /
    10
  [BF=0]
```

> Notice: The height of node `20` is 1 (it has one edge going down to `10`). The height of node `30`'s left subtree is 1 (because `20` is at height 1).

---

#### Example 3 — Five nodes, violation appears

Now insert `5` into the tree above:

```
        30
       /  \
      20   40
     /
    10
   /
  5
```

**Bottom up:**

| Node | Left child | Left height | Right child | Right height | BF = Left − Right |
|:----:|:----------:|:-----------:|:-----------:|:------------:|:-----------------:|
| 5    | NULL       | **-1**      | NULL        | **-1**       | **0**             |
| 10   | node 5     | **0**       | NULL        | **-1**       | 0 − (-1) = **+1** |
| 40   | NULL       | **-1**      | NULL        | **-1**       | **0**             |
| 20   | node 10    | **1**       | NULL        | **-1**       | 1 − (-1) = **+2** ← **VIOLATION!** |
| 30   | node 20    | **2**       | node 40     | **0**        | 2 − 0 = **+2** ← **VIOLATION!** |

```
          30 [BF=+2] ⚠️
         /  \
        20   40
    [BF=+2] ⚠️  [BF=0]
       /
      10
   [BF=+1]
      /
     5
   [BF=0]
```

> **Rule:** When you find multiple violations going bottom-up, you always fix the **lowest** (deepest) violation first. Here, fix node `20` first.

---

#### Example 4 — Right-heavy tree

```
      10
        \
         20
           \
            30
```

| Node | Left child | Left height | Right child | Right height | BF = Left − Right |
|:----:|:----------:|:-----------:|:-----------:|:------------:|:-----------------:|
| 30   | NULL       | **-1**      | NULL        | **-1**       | **0**             |
| 20   | NULL       | **-1**      | node 30     | **0**        | -1 − 0 = **-1**   |
| 10   | NULL       | **-1**      | node 20     | **1**        | -1 − 1 = **-2** ← **VIOLATION!** |

```
  10 [BF=-2] ⚠️
    \
     20 [BF=-1]
       \
        30 [BF=0]
```

BF = -2 means the **right side** is 2 levels heavier than the left.

---

#### Example 5 — Bigger balanced tree (verify you can do it)

```
        40
       /  \
      20   60
     / \   / \
    10  30 50  70
```

| Node | Left height | Right height | BF |
|:----:|:-----------:|:------------:|:--:|
| 10   | -1          | -1           | 0  |
| 30   | -1          | -1           | 0  |
| 50   | -1          | -1           | 0  |
| 70   | -1          | -1           | 0  |
| 20   | 0 (node 10) | 0 (node 30)  | 0  |
| 60   | 0 (node 50) | 0 (node 70)  | 0  |
| 40   | 1 (node 20) | 1 (node 60)  | 0  |

Every node has BF = 0 → **Perfect AVL tree** ✅

---

### The Recipe — How to Calculate BF for Any Node

```
  1. Find the LEFT child of the node.
     - If it exists → its height = (1 + max height among ITS children)
     - If it does NOT exist → height = -1

  2. Find the RIGHT child of the node.
     - Same rules as above.

  3. BF = Left height − Right height

  4. Always calculate bottom-up (start from leaf nodes, work up to root).
```

### When Does It Break?

Whenever you insert a node, walk **upward** recalculating BFs. The moment any node gets BF = **+2** or **-2**, a rotation is needed.

```
          30 [BF=+2] ⚠️ UNBALANCED!
         /  \
        20   40
    [BF=+2] ⚠️  [BF=0]
       /
      10
   [BF=+1]
      /
     5
   [BF=0]
```

- Both node `20` and node `30` have BF = **+2** → two **VIOLATIONS**!
- Fix the **lowest** violation first (node `20`), and after rotating, node `30` automatically becomes balanced too.
- We need a **rotation** to fix this.

---

## 5. The 4 Types of Rotations

### What is a Rotation?

A **rotation** is a small, local operation that moves nodes around to fix an imbalance — without breaking the BST ordering rule.

It only affects **2–3 nodes** (and their subtrees) at a time. Everything else in the tree stays untouched.

#### Why is it called a "rotation"?

Look at the link between a parent and its child. A rotation "spins" that link — one node climbs up, the other swings down, like a see-saw pivoting around a point:

```
  BEFORE Right Rotation:      AFTER Right Rotation:

        Z                           Y
       /           ──▶            /   \
      Y                          ?     Z

  The Z–Y link has "rotated":
  Y was below Z (pointing left),
  now Z is below Y (pointing right).
  It looks like the link rotated 90° clockwise.
```

- **Right Rotation** → the left child climbs up; the subtree tilts to the right
- **Left Rotation** → the right child climbs up; the subtree tilts to the left

#### What makes a rotation safe?

A rotation **preserves the in-order (sorted) sequence** of all nodes. If the BST order was correct before the rotation, it is still correct after. The tree just has a different shape — like reshuffling books on a shelf without changing their alphabetical order.

#### What does a rotation actually change?

| What changes | What stays the same |
|---|---|
| Which node is the local root | In-order traversal (BST sorted order) |
| Parent–child pointers between 2–3 nodes | All other nodes in the tree |
| Heights and balance factors of affected nodes | Values stored in nodes |

---

### The 4 Cases

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

#### Example: Insert 30, 20, 35, 10, 25 — then insert 5 (triggers LL violation at node 30)

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
