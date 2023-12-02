import Foundation

var dict: Dictionary<String, Int> = [:]
var count = 0

while let input = readLine() {
    dict[input] = dict[input] ?? 0
    dict[input]! += 1
        
    count += 1
}

dict.keys.sorted().forEach{
    print("\($0) \(String(format:"%.4f", (Double(dict[$0]!)*100/Double(count))))")
}

