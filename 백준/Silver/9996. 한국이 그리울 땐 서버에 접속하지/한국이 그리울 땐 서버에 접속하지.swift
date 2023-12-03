let N = Int(readLine()!)!

let pattern = readLine()!.split(separator: "*")

for _ in 0..<N {
    let str = readLine()!
    
    if str.hasPrefix(pattern[0]) && str.hasSuffix(pattern[1]) && pattern[0].count + pattern[1].count <= str.count{
        print("DA")
    } else {
        print("NE")
    }
}
