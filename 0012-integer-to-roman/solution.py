class Solution:
    def intToRoman(self, num: int) -> str:
        result = ""
        while(num != 0):
            if num >= 1000:
                num -= 1000
                result += "M"

            if num >= 900 and num < 1000:
                num -= 900
                result += "CM"  

            if num >= 500 and num < 900:
                num -= 500
                result += "D"

            if num >= 400 and num < 500:
                num -= 400
                result += "CD"

            if num >= 100 and num < 400:
                num -= 100
                result += "C"
            if num >= 90 and num < 100:
                num -= 90
                result += "XC"

            if num >= 50 and num < 90:
                num -= 50
                result += "L"

            if num >= 40 and num < 50:
                num -= 40
                result += "XL"

            if num >= 10 and num < 40:
                num -= 10
                result += "X"

            if num == 9:
                num -= 9
                result += "IX"

            if num >= 5 and num < 9:
                num -= 5
                result += "V"

            if num == 4:
                num -= 4
                result += "IV"

            if num >= 1 and num < 4:
                num -= 1
                result += "I"
        return result

