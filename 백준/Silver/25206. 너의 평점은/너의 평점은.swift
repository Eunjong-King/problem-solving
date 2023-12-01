import Foundation

var totalGrade = 0.0
var total = 0.0

for _ in 1...20 {
    let input = readLine()!.split(separator: " ")
    
    totalGrade += Double(input[1])!
    
    switch input[2] {
    case "A+":
        total += Double(input[1])! * 4.5
    case "A0":
        total += Double(input[1])! * 4.0
    case "B+":
        total += Double(input[1])! * 3.5
    case "B0":
        total += Double(input[1])! * 3.0
    case "C+":
        total += Double(input[1])! * 2.5
    case "C0":
        total += Double(input[1])! * 2.0
    case "D+":
        total += Double(input[1])! * 1.5
    case "D0":
        total += Double(input[1])! * 1.0
    case "F":
        total += Double(input[1])! * 0.0
    default:
        totalGrade -= Double(input[1])!
    }
}

let str = String(format: "%.6f", total/totalGrade)
print(str)
