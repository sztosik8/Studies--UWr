function Tree(val, left, right) {
    this.left = left;
    this.right = right;
    this.val = val;
}

Tree.prototype[Symbol.iterator] = function* () {
    // breadth-first search
    var queue = [this];
    while (queue.length > 0) {
        var tree = queue[0];
        queue.splice(0, 1);
        yield tree.val;
        if (tree.left) queue.push(tree.left);
        if (tree.right) queue.push(tree.right);
    }
}


var root = new Tree(1, new Tree(2, new Tree(3)), new Tree(4));

for (var e of root) {
    console.log(e);
}


