import kotlin.math.min

const val MAXK = 17
const val MAXN = MAXK * 2
const val MODVAL = 998244353

fun modAdd(a: Int, b: Int) = ((a + b) % MODVAL + MODVAL) % MODVAL
fun modMul(a: Int, b: Int) = (a.toLong() * b % MODVAL).toInt()
fun modPow(baseInit: Int, expInit: Int): Int {
    var res = 1
    var base = baseInit
    var exp = expInit
    while (exp > 0) {
        if ((exp and 1) == 1) res = modMul(res, base)
        base = modMul(base, base)
        exp = exp shr 1
    }
    return res
}

data class NodeState(var free: Int, var smallerFree: Int, var smallerPaired: Int, var mark: Int, var count: Int)

fun lessThan(a: NodeState, b: NodeState): Boolean {
    if (a.free != b.free) return a.free < b.free
    if (a.smallerFree != b.smallerFree) return a.smallerFree < b.smallerFree
    if (a.smallerPaired != b.smallerPaired) return a.smallerPaired < b.smallerPaired
    return a.mark < b.mark
}

fun normalize(list: MutableList<NodeState>) {
    list.sortWith(compareBy(NodeState::free).thenBy { it.smallerFree }.thenBy { it.smallerPaired }.thenBy { it.mark })
    val temp = mutableListOf<NodeState>()
    for (s in list) {
        if (s.count == 0) continue
        if (temp.isEmpty() || lessThan(temp.last(), s)) temp.add(s)
        else temp.last().count = modAdd(temp.last().count, s.count)
    }
    list.clear()
    list.addAll(temp)
}

val factorial = IntArray(MAXN)
val invFactorial = IntArray(MAXN)
val graph = Array(MAXN) { mutableListOf<Int>() }
val dpTable = Array(MAXN) { mutableListOf<MutableList<NodeState>>() }
var nodeCount = 0

fun nCr(n: Int, r: Int) = modMul(factorial[n], modMul(invFactorial[r], invFactorial[n - r]))

fun combineStates(aList: MutableList<NodeState>, bList: MutableList<NodeState>): MutableList<NodeState> {
    val res = mutableListOf<NodeState>()
    for (a in aList) for (b in bList) {
        for (pLess in 0..min(a.smallerFree, b.smallerFree)) {
            for (pGreater in 0..min(a.free - a.smallerFree, b.free - b.smallerFree)) {
                var ways = modMul(factorial[pLess], factorial[pGreater])
                ways = modMul(ways, nCr(a.smallerFree, pLess))
                ways = modMul(ways, nCr(a.free - a.smallerFree, pGreater))
                ways = modMul(ways, nCr(b.smallerFree, pLess))
                ways = modMul(ways, nCr(b.free - b.smallerFree, pGreater))
                ways = modMul(ways, modMul(a.count, b.count))
                var flagVal = 0
                if (a.smallerFree > 0 || b.smallerFree > 0) flagVal = 1
                if (a.smallerFree < a.free || b.smallerFree < b.free) flagVal = 2
                res.add(
                    NodeState(
                        a.free + b.free - 2 * pLess - 2 * pGreater,
                        a.smallerFree + b.smallerFree - 2 * pLess,
                        a.smallerPaired + b.smallerPaired + pLess,
                        maxOf(flagVal, a.mark),
                        ways
                    )
                )
            }
        }
    }
    normalize(res)
    return res
}

fun joinLists(A: MutableList<MutableList<NodeState>>, B: MutableList<MutableList<NodeState>>): MutableList<MutableList<NodeState>> {
    val result = MutableList(2) { mutableListOf<NodeState>() }
    for (i in 0..1) for (j in 0..1) {
        if (i == 1 && j == 1) continue
        result[i + j].addAll(combineStates(A[i], B[j]))
    }
    for (i in 0..1) normalize(result[i])
    return result
}

fun fetchValue(list: MutableList<NodeState>, cntSmaller: Int, markVal: Int): Int {
    for (x in list) if (x.free == 0 && x.smallerPaired == cntSmaller && x.mark == markVal) return x.count
    return 0
}

fun markSpecial(a: MutableList<MutableList<NodeState>>): MutableList<MutableList<NodeState>> {
    val res = MutableList(2) { mutableListOf<NodeState>() }
    for (x in a[0]) {
        when (x.mark) {
            0 -> res[1].add(x)
            1 -> {
                res[0].add(x.copy())
                res[1].add(x.copy())
            }
            else -> res[0].add(x)
        }
    }
    for (x in a[1]) res[1].add(x)
    normalize(res[0]); normalize(res[1])
    return res
}

fun dfsTree(v: Int, parent: Int) {
    val children = mutableListOf<Int>()
    for (u in graph[v]) if (u != parent) {
        dfsTree(u, v)
        children.add(u)
    }
    if (graph[v].size == 1 && v != parent) {
        val st1 = NodeState(1, 1, 0, 0, 1)
        val st2 = NodeState(1, 0, 0, 0, 1)
        dpTable[v] = mutableListOf(mutableListOf(st1, st2), mutableListOf())
        normalize(dpTable[v][0])
        return
    }
    var acc = MutableList(2) { mutableListOf<NodeState>() }
    acc[0].add(NodeState(0, 0, 0, 0, 1))
    for (c in children) acc = joinLists(acc, dpTable[c])
    dpTable[v] = markSpecial(acc)
}

fun main() {
    val input = System.`in`.bufferedReader()
    nodeCount = input.readLine().trim().toInt()
    repeat(nodeCount - 1) {
        val (a, b) = input.readLine().trim().split(" ").map { it.toInt() }
        graph[a - 1].add(b - 1)
        graph[b - 1].add(a - 1)
    }
    val leafNodes = mutableListOf<Int>()
    val innerNodes = mutableListOf<Int>()
    for (i in 0 until nodeCount) if (graph[i].size == 1) leafNodes.add(i) else innerNodes.add(i)
    factorial[0] = 1
    for (i in 1..nodeCount) factorial[i] = modMul(factorial[i - 1], i)
    for (i in 0..nodeCount) invFactorial[i] = modPow(factorial[i], MODVAL - 2)
    var answer = 0
    if (leafNodes.size % 2 == 0) {
        val root = innerNodes[0]
        dfsTree(root, root)
        answer = modMul(factorial[leafNodes.size / 2], fetchValue(dpTable[root][0], 0, 2))
        println("${leafNodes.size / 2} $answer")
    } else {
        print("${(leafNodes.size + 1) / 2} ")
        for (lf in leafNodes) {
            dfsTree(lf, lf)
            for (j in 0..leafNodes.size / 2) {
                val curr = fetchValue(dpTable[lf][1], j, 0)
                answer = modAdd(answer, modMul(curr, modMul(factorial[j], factorial[leafNodes.size / 2 - j])))
            }
        }
        println(answer)
    }
}