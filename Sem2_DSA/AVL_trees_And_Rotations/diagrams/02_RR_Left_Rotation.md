# RR Case — Single Left Rotation

## When does this happen?
New node was inserted into the **Right** subtree of the **Right** child.
The unbalanced node has BF = **-2**, its right child has BF = **-1**.

---

## Simple Case (3 nodes)

```
  Insert order: 10 → 20 → 30

  10                            20
    \                          /  \
     20       ──LEFT──▶      10   30
       \      ROTATE on 10
        30
```

---

## General Case (with subtrees T1, T2, T3, T4)

```
  BEFORE:                              AFTER Left Rotation on Z:

     Z  (BF=-2)                              Y
    / \                                     / \
  T1   Y                                  Z    X
      / \                                / \  / \
    T2   X                             T1 T2 T3 T4
        / \
      T3   T4

  Where: T1 < Z < T2 < Y < T3 < X < T4
```

### What moves where:
1. **Y** moves UP to replace Z
2. **Z** becomes Y's LEFT child
3. **T2** (Y's old left child) becomes Z's RIGHT child ← This is the key step!
4. Everything else stays in place

---

## Step-by-Step Pointer Changes

```
  temp = Z.right         // temp = Y
  Z.right = temp.left    // Z.right = T2  (re-attach orphan)
  temp.left = Z          // Y.left = Z    (Z goes under Y)
  // Update the parent of Z to point to Y instead
```

---

## Verify BST Order Is Preserved

Before:  T1 < Z < T2 < Y < T3 < X < T4
After:   T1 < Z < T2 < Y < T3 < X < T4  ✅ Same!

---

## Mirror Relationship

> RR rotation is the **exact mirror** of LL rotation.
> If you understand one, flip left↔right and you have the other.
