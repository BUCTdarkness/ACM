class DBConnectionPool{
		//////////////////////////////////////////////////////////
		//public 变量
		/**默认最大连接数*/
		public final int DEFAULT_MAX_CONNECTION_COUNT = 30;
		public final int DEFAULT_ADD_CONNECTION_STEP = 10;
		//////////////////////////////////////////////////////////
		//private 变量
		private boolean Avaluable = false;//是否可用
		private String Name = "";//连接池名字
		private String Url = "";//数据库JDBC URL
		private String User = "";//数据库账号
		private String Pass = "";//数据库密码
		private int    ConnAddStep = 10;//连接池增长步长，默认为10，不能超过20，不能小于2
		private int    ConnMaxCount = 30;//最大连接数,默认30，不能小于10
		private LinkedList<Connection> FreeConnectionList 
				= new LinkedList<Connection>();
		private LinkedList<Connection> BusyConnectionList
				= new LinkedList<Connection>();
		//////////////////////////////////////////////////////////
		//private 方法
		/**创建新连接*/
		private Connection newConnection(){
			Connection conn = null;
			try{
				conn = DriverManager.getConnection(Url, User, Pass);
			} catch (SQLException e) {
				System.out.println("无法创建下列URL的连接: " + Url);
				e.printStackTrace();
				return null;
			}
			return conn;
		}//End newConnection
		/**测试连接是否可用*/
		private boolean testConnection(){
			Connection conn = null;
			conn = newConnection();
			boolean b = false;
			if(conn != null){
				try {
					conn.close();
					System.out.println("测试连接通过！");
					b = true;
					Avaluable = true;
				} catch (SQLException e) {
					b = false;
					System.out.println("关闭连接失败");
					e.printStackTrace();
				}
			}else{
				System.out.println("创建连接失败");
			}
			return b;
		}//End testConnection
		/**向连接池补充连接*/
		private synchronized void addConnections(){
			for (int i = 0 ; i < ConnAddStep ; i ++){
				FreeConnectionList.addLast(getConnection());
			}
		}
		/**扫描busyConnectionList中的连接，删除失效的连接*/
		private synchronized void scanBusyConnectionList(){
			Iterator<Connection> tmpit = BusyConnectionList.iterator();
			while(tmpit.hasNext()){
				Connection tmpConn = tmpit.next();
				try {
					if(tmpConn.isClosed()){
						BusyConnectionList.remove(tmpConn);
					}
				} catch (SQLException e) {
					BusyConnectionList.remove(tmpConn);
				}
			}
		}//End scanBusyConnectionList
		
		
		//////////////////////////////////////////////////////////
		//public 方法
		
		/**返回是否可用*/
		public boolean isAvaluable(){return Avaluable;}
		/**激活连接池*/
		public boolean active(
				String databaseConnectionPoolName,
				String databaseURL,
				String databaseUser,
				String databasePassword,
				int addConnectionStep,
				int maxConnectionCount
				){
			if(Avaluable){return true;}
			boolean b = false;
			Name = databaseConnectionPoolName;
			Url  = databaseURL;
			User = databaseUser;
			Pass = databasePassword;
			ConnAddStep = addConnectionStep;
			ConnMaxCount = maxConnectionCount;
			b = testConnection();
			if(b){
				if( ConnAddStep < 2 || ConnAddStep > 20){
					ConnAddStep = DEFAULT_ADD_CONNECTION_STEP;
				}
				if( ConnMaxCount < 10 ){
					ConnMaxCount = DEFAULT_MAX_CONNECTION_COUNT;
				}/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
private:
	vector<vector<int>> ans;
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) 
    {
        ans.clear();
        vector<int> a;
        dfs(root,sum,0,a);
        return ret;
    }
    void dfs(TreeNode *node,int sum,int curSum,vector<int> a)
    {
    	if(node==NULL)
    	{
    		return;
    	}
    	if(node->left==NULL&&node->right==NULL)
    	{
    		if(curSum+node->val==sum)
    		{
    			a.push_back(node->val);
    			ans.push_back(a);
    		}
    		return;
    	}
    	a.push_back(node->val);
    	dfs(node->left,sum,curSum+node->val,a);
    	dfs(node->right,sum,curSum+node->val,a);
    }
};

				addConnections();
			}
			
			return b;
		}//End boolean active
		/**<b>获取连接</b><br />
		 * 无空闲连接且连接数小于最大连接数限制，则创建新连接<br />
		 * 若获取的连接不再有效，则从LinkedList中删除<br />
		 * 再尝试获取新连接
		 */
		public synchronized Connection getConnection(){
			if (!Avaluable){
				System.out.println("连接池未激活！！！");
				return null;
			}
			Connection conn = null;
			if(FreeConnectionList.size() > 0){
				conn = FreeConnectionList.removeFirst();
				try {
					if(conn == null || conn.isClosed()){
						System.out.println("已从连接池" + Name + "删除无效连接");
						conn = getConnection();
					}else{
						BusyConnectionList.addLast(conn);
					}
				} catch (SQLException e) {
					System.out.println("已从连接池" + Name + "删除无效连接");
					conn = getConnection();
				}
			} else if(FreeConnectionList.size() + BusyConnectionList.size() < ConnMaxCount - ConnAddStep){
				if(testConnection()){
					addConnections();
					conn = getConnection();
				}else{
					return null;
				}
			} else {
				scanBusyConnectionList();
				try {
					wait(1000);
					conn = getConnection();
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
			return conn;
		}//End getConnection
		/**释放连接*/
		public synchronized void freeConnection(Connection conn){
			try {
				if (conn == null || conn.isClosed()){
					conn = null;
				} else {
					if(BusyConnectionList.remove(conn)){
						FreeConnectionList.addLast(conn);
					}
				}
			} catch (SQLException e) {
				conn = null;
			}
		}//End freeConnection
		/**关闭连接池*/
		public synchronized void closePool(){
			Avaluable = false;
			System.out.println("Closing...");
			while(!FreeConnectionList.isEmpty()){
				Connection conn = FreeConnectionList.removeFirst();
				try {
					conn.close();
				} catch (SQLException e) {
					
				}
			}
			for (int i = 0 ; i < 5 ; i ++){
				while(!BusyConnectionList.isEmpty()){
					try {
						wait(1000);
						scanBusyConnectionList();
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
				}
			}
			while(!FreeConnectionList.isEmpty()){
				Connection conn = FreeConnectionList.removeFirst();
				try {
					conn.close();
				} catch (SQLException e) {
					
				}
			}
			System.out.println("Closed");
		}
		
		
	}//End class