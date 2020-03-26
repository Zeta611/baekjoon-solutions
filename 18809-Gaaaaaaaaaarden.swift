// Swift is too slow for this problem
// Solved in C++ using exactly the same algorithm

struct Queue<Element> {
    private var array = [Element?](repeating: nil, count: 2500)

    private var headIndex = 0
    private var tailIndex = 0

    var isEmpty: Bool { headIndex == tailIndex }

    mutating func enqueue(_ newElement: Element) {
        array[tailIndex] = newElement
        if tailIndex == array.count - 1 {
            tailIndex = 0
        } else {
            tailIndex += 1
        }
    }

    mutating func dequeue() -> Element {
        let dequeued = array[headIndex]!
        if headIndex == array.count - 1 {
            headIndex = 0
        } else {
            headIndex += 1
        }
        return dequeued
    }

    var head: Element? { array[headIndex] }
}

enum Color { case green, red }

enum State: Equatable {
    case lake
    case cultivable
    case uncultivable
    case cultivated(Color, Int)
    case flourished

    init(int: Int) {
        switch int {
        case 0: self = .lake
        case 1: self = .uncultivable
        case 2: self = .cultivable
        default: fatalError()
        }
    }
}

struct Point: Equatable {
    let x: Int
    let y: Int

    var tuple: (Int, Int) { (x, y) }

    init(tuple: (Int, Int)) { (x, y) = tuple }

    init(x: Int, y: Int) { (self.x, self.y) = (x, y) }

    static let zero = Point(x: 0, y: 0)
}

func maximumFlowers(garden: [[State]], cultivableCells: [Point]) -> Int {
    var garden = garden
    let row = garden.count
    let column = garden[0].count

    func visit(_ point: Point, color: Color, distance: Int) -> Bool {
        guard (0..<row).contains(point.x) && (0..<column).contains(point.y)
            else { return false }

        let (x, y) = point.tuple
        switch garden[x][y] {
        case .cultivable, .uncultivable:
            garden[x][y] = .cultivated(color, distance)
            return true

        case let .cultivated(otherColor, otherDistance):
            if color != otherColor && distance == otherDistance {
                garden[x][y] = .flourished
            }
            return false

        case .lake, .flourished:
            return false
        }
    }

    func visitAdjacents(
        from point: Point,
        color: Color,
        distance: Int
    ) -> [Point] {
        [(1, 0), (0, 1), (-1, 0), (0, -1)]
            .map { Point(x: point.x + $0.0, y: point.y + $0.1) }
            .filter { visit($0, color: color, distance: distance) }
    }

    func bfs() {
        var greenQueue = Queue<Point>()
        var redQueue = Queue<Point>()
        for cell in cultivableCells {
            if case let .cultivated(color, _) = garden[cell.x][cell.y] {
                switch color {
                case .green: greenQueue.enqueue(cell)
                case .red: redQueue.enqueue(cell)
                }
            }
        }

        var currentDistance = 0
        while !greenQueue.isEmpty || !redQueue.isEmpty {
            if let head = greenQueue.head,
                case let .cultivated(_, distance) = garden[head.x][head.y],
                currentDistance == distance
            {
                let head = greenQueue.dequeue()
                visitAdjacents(
                    from: head,
                    color: .green,
                    distance: distance + 1
                )
                    .forEach { greenQueue.enqueue($0) }
            } else if let head = greenQueue.head,
                garden[head.x][head.y] == .flourished
            {
                let _ = greenQueue.dequeue()
            } else if let head = redQueue.head,
                case let .cultivated(_, distance) = garden[head.x][head.y],
                currentDistance == distance
            {
                let head = redQueue.dequeue()
                visitAdjacents(
                    from: head,
                    color: .red,
                    distance: distance + 1
                )
                    .forEach { redQueue.enqueue($0) }
            } else {
                currentDistance += 1
            }
        }
    }

    bfs()

    return garden.reduce(0) { $0 + $1.filter { $0 == .flourished }.count }
}

func solve(
    _ garden: inout [[State]],
    cultivableCells: [Point],
    greens: Int,
    reds: Int
) -> Int {
    var result = -1
    func inner(left: Int, color: Color, progress: Int) {
        if left == 0 {
            switch color {
            case .green:
                inner(left: reds, color: .red, progress: .zero)
            case .red:
                result = max(
                    result,
                    maximumFlowers(
                        garden: garden,
                        cultivableCells: cultivableCells
                    )
                )
            }
        } else {
            for i in progress..<cultivableCells.count {
                let cell = cultivableCells[i]
                guard garden[cell.x][cell.y] == .cultivable else { continue }
                garden[cell.x][cell.y] = .cultivated(color, 0)
                inner(left: left - 1, color: color, progress: i + 1)
                garden[cell.x][cell.y] = .cultivable
            }
        }
    }
    inner(left: greens, color: .green, progress: .zero)
    return result
}

let input = readLine()!.split(separator: " ").map { Int($0)! }
let row = input[0]
let column = input[1]
let greens = input[2]
let reds = input[3]

var garden = [[State]](
    repeating: [State](repeating: .lake, count: column),
    count: row
)
var cultivableCells = [Point]()

for i in 0..<row {
    readLine()!
        .split(separator: " ")
        .map({ State(int: Int($0)!) })
        .enumerated()
        .forEach {
            let (j, state) = $0
            garden[i][j] = state
            if state == .cultivable {
                cultivableCells.append(Point(x: i, y: j))
            }
        }
}

print(
    solve(
        &garden,
        cultivableCells: cultivableCells,
        greens: greens,
        reds: reds
    )
)
