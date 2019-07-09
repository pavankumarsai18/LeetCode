import collections
class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        c = {}
        for cd in cpdomains:
            n, d = cd.split()
            n = int(n)
            if d in c:
                c[d] += n
            else:
                c[d] = n
                
            for i in range(len(d)):
                if d[i] == '.':
                    if d[i+1:] in c:
                        c[d[i + 1:]] += n
                    else:
                        c[d[i + 1:]] = n
        return ["%d %s" % (c[k], k) for k in c]
        
#         d_c = collections.Counter()
        
#         domain_count = {}
        
#         for domain_num in cpdomains:
#             [num, website] = domain_num.split(" ")
#             num = int(num)
#             domain_count[website] = num
#             i = 0
#             while i < len(website):
#                 s = ""
#                 while i < len(website) and website[i] != ".":
#                     i += 1
#                 s = website[i+1:]
#                 if s != "" and s not in domain_count:
#                     domain_count[s] = num
#                 elif s in domain_count:
#                     domain_count[s] += num
#                 i += 1            
        
#         return list(str(domain_count[key]) + " " + key for key in domain_count)
        
            
