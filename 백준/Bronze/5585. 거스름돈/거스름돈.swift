import Foundation

var change = 1000 - Int(readLine()!)!

var result: Int = 0

if change >= 500 {
    result += change/500
    change -= 500 * Int(change/500)
}
if change >= 100 {
    result += change/100
    change -= 100 * Int(change/100)
}
if change >= 50 {
    result += change/50
    change -= 50 * Int(change/50)
}
if change >= 10 {
    result += change/10
    change -= 10 * Int(change/10)
}
if change >= 5 {
    result += change/5
    change -= 5 * Int(change/5)
}
result += change

print(result)
