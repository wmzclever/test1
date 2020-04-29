class Testfun(unittest.TestCase):
    def test_put_data(self,r):
        try:
            r.put_data(['123'])
        except:
            print('输入单元有错')
            
    def test_put_result(self,r):
        try:
            r.put_result(['123'])
        except:
            print('结果单元有错')
    
    def test_equal(self,r):
        self.assertEqual(r.res,r.for)

interface r
r.mainloop()
Testfun t
t.test_put_data(r)
t.test_put_result(r)
t.test_equal(r)
