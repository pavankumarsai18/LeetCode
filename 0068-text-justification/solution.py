class Solution(object):
    def fullJustify(self, words, maxWidth):
        
        lines = []
        
        i = 0
        
        while i < len(words):
            j = i
            line = []
            curLength = 0
            while i < len(words) and curLength <= maxWidth:
                if curLength + len(words[i]) + 1 <= maxWidth:
                    line.append(words[i])
                    curLength += len(words[i])+1
                    i += 1
                else:
                    if curLength + len(words[i]) <= maxWidth:
                        line.append(words[i])
                        curLength += len(words[i])
                        i += 1
                    break
            lines.append(line)
            
            
        result = []
        
        for index, line in enumerate(lines):
            length = sum([len(word) for word in line])
            spaces = maxWidth - length
            
            lineString = ""
            if index != len(lines) - 1:
                if len(line) == 1:
                    lineString += line[0] + " "*spaces
                else:
                    remainder = spaces%(len(line)-1)
                    evenPadding = spaces//(len(line)-1)
                    for i in xrange(len(line)):
                        spacing = " "*evenPadding
                        lineString += line[i]
                        if i < remainder:
                            lineString += spacing + " "
                        elif i != len(line)-1:
                            lineString += spacing
            else:
                for i in xrange(len(line)):
                    lineString += line[i]
                    if i != len(line) - 1:
                        lineString +=" "
                lineString += " "*(spaces - len(line) + 1)
            result.append(lineString)
        return result
                
