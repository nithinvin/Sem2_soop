# RL Case — Double Rotation (Right then Left)

## When does this happen?
New node was inserted into the **Left** subtree of the **Right** child.
The unbalanced node has BF = **-2**, its right child has BF = **+1**.
Creates a **zig-zag** pattern (mirror of LR).

---

## Simple Case (3 nodes)

```
  Insert order: 10 → 30 → 20

  10                     10                       20
    \                      \                     /  \
     30    ──RIGHT──▶       20    ──LEFT──▶    10    30
    /      ROTATE on 30       \    ROTATE on 10
   20                          30

  Step 1: Right Rotate      Step 2: Left Rotate
  on right child (30)       on unbalanced node (10)
```

---

## General Case (with subtrees T1, T2, T3, T4)

```
  BEFORE:

       Z  (BF=-2)
      / \
    T1   X
        / \
       Y   T4       ← zig-zag: right child's LEFT subtree
      / \
    T2   T3

  Where: T1 < Z < T2 < Y < T3 < X < T4
```

### Step 1: Right Rotate on X (right child)

```
       Z
      / \
    T1   Y
        / \
      T2   X
          / \
        T3   T4
```
Now it's a straight RR pattern!

### Step 2: Left Rotate on Z (unbalanced node)

```
            Y
           / \
          Z    X
         / \  / \
       T1 T2 T3 T4
```

**Final result: Perfectly balanced!** ✅

---

## What moves where (across both steps):
1. **Y** (the grandchild) moves ALL the way UP to the root
2. **Z** becomes Y's LEFT child
3. **X** becomes Y's RIGHT child
4. **T2** becomes Z's RIGHT child (was Y's left)
5. **T3** becomes X's LEFT child (was Y's right)

---

## Verify BST Order Is Preserved

Before:  T1 < Z < T2 < Y < T3 < X < T4
After:   T1 < Z < T2 < Y < T3 < X < T4  ✅ Same!

---

## Mirror Relationship

> RL rotation is the **exact mirror** of LR rotation.
> LR = Left on child, then Right on node
> RL = Right on child, then Left on node
