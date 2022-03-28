class Solution(object):
    def reformatDate(self, date):
        """
        :type date: str
        :rtype: str
        """
        
        month_num = dict()
        months = ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"]
        
        count = 1
        for month in months:
            month_num[month] = str(count) if count >= 10  else "0" + str(count)
            count += 1
        
        info = date.split(" ")
        date = info[0][:-2]
        month = info[1]
        year = info[2]
        
        if int(date) < 10:
            date = "0" + date
        return year + "-" + str(month_num[month]) + "-" + date
        
        
