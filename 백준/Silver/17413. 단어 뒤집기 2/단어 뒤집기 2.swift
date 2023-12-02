import Foundation

let input = readLine()!

var isTag = false
var temp: String = ""
var result: String = ""

for c in input {
    if c == "<" {
        isTag = true
        result += temp.reversed()
        temp = ""
    }
    
    if isTag == false && c == " " {
        result += temp.reversed() + " "
        temp = ""
        
        continue
    }
    
    temp += String(c)
    
    if c == ">" {
        isTag = false
        result += temp
        temp = ""
    }
}

if isTag {
    result += temp
} else {
    result += temp.reversed()
}

print(result)
