# LR Case — Double Rotation (Left then Right)

## When does this happen?
New node was inserted into the **Right** subtree of the **Left** child.
The unbalanced node has BF = **+2**, its left child has BF = **-1**.
Creates a **zig-zag** pattern.

---

## Simple Case (3 nodes)

```
  Insert order: 30 → 10 → 20

      30                   30                     20
     /                    /                      /  \
    10     ──LEFT──▶     20     ──RIGHT──▶     10    30
      \    ROTATE on 10 /       ROTATE on 30
       20              10

  Step 1: Left Rotate      Step 2: Right Rotate
  on left child (10)       on unbalanced node (30)
```

### Why one rotation doesn't work:
```
  If we ONLY did Right Rotation on 30:

      30           10
     /     →         \
    10                30
      \              /
       20           20        ← Still not balanced!
```

---

## General Case (with subtrees T1, T2, T3, T4)

```
  BEFORE:

           Z  (BF=+2)
          / \
         X   T4
        / \
      T1   Y        ← zig-zag: left child's RIGHT subtree
          / \
        T2   T3

  Where: T1 < X < T2 < Y < T3 < Z < T4
```

### Step 1: Left Rotate on X (left child)

```
           Z
          / \
         Y   T4
        / \
       X   T3
      / \
    T1   T2
```
Now it's a straight LL pattern!

### Step 2: Right Rotate on Z (unbalanced node)

```
            Y
           / \
          X    Z
         / \  / \
       T1 T2 T3 T4
```

**Final result: Perfectly balanced!** ✅

---

## What moves where (across both steps):
1. **Y** (the grandchild) moves ALL the way UP to the root
2. **X** becomes Y's LEFT child
3. **Z** becomes Y's RIGHT child
4. **T2** becomes X's RIGHT child (was Y's left)
5. **T3** becomes Z's LEFT child (was Y's right)

---

## Verify BST Order Is Preserved

Before:  T1 < X < T2 < Y < T3 < Z < T4
After:   T1 < X < T2 < Y < T3 < Z < T4  ✅ Same!
