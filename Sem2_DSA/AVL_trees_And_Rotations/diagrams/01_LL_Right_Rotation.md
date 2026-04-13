# LL Case — Single Right Rotation

## When does this happen?
New node was inserted into the **Left** subtree of the **Left** child.
The unbalanced node has BF = **+2**, its left child has BF = **+1**.

---

## Simple Case (3 nodes)

```
  Insert order: 30 → 20 → 10

      30                        20
     /                         /  \
    20        ──RIGHT──▶      10   30
   /          ROTATE on 30
  10
```

---

## General Case (with subtrees T1, T2, T3, T4)

```
  BEFORE:                              AFTER Right Rotation on Z:

         Z  (BF=+2)                          Y
        / \                                 / \
       Y   T4                              X    Z
      / \                                 / \  / \
     X   T3                             T1 T2 T3 T4
    / \
  T1   T2

  Where: T1 < X < T2 < Y < T3 < Z < T4
```

### What moves where:
1. **Y** moves UP to replace Z
2. **Z** becomes Y's RIGHT child
3. **T3** (Y's old right child) becomes Z's LEFT child ← This is the key step!
4. Everything else stays in place

---

## Step-by-Step Pointer Changes

```
  temp = Z.left          // temp = Y
  Z.left = temp.right    // Z.left = T3  (re-attach orphan)
  temp.right = Z         // Y.right = Z  (Z goes under Y)
  // Update the parent of Z to point to Y instead
```

---

## Verify BST Order Is Preserved

Before:  T1 < X < T2 < Y < T3 < Z < T4
After:   T1 < X < T2 < Y < T3 < Z < T4  ✅ Same!
