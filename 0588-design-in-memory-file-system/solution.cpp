class FileSystem {
private:
    unordered_map<string, unordered_set<string>> directories;
    unordered_map<string, string> fileContent;
    unordered_set<string> files;
    unordered_map<string, vector<string>> lsCache;
    
public:
    FileSystem() 
    {
        directories["/"] = unordered_set<string>();
        
    }
    void printDir()
    {
        cout<<"Directories"<<endl;
        for(auto & [dir, subDirs]: directories)
        {
            cout<<dir<<": ";
            for(auto & subDir: subDirs)
            {
                cout<<subDir<<" ";
            }
            cout<<endl;
        }
    }
    void print()
    {
        printDir();
        cout<<"fileContent\n";
        for(auto & [file, content]: fileContent)
        {
            cout<<file<<": "<<content<<endl;   
        }
    }
    vector<string> ls(string path) 
    {
        // cout<<"ls "<<path<<endl;   
        if(path[path.size()-1] != '/')
            path += '/';
        
        if(files.find(path) != files.end())
        {
            string fileName = "";
            for(int i = path.size()-1-1; i >= 0; i--)
            {
                if(path[i]=='/')
                    break;
                fileName += path[i];
            }
            reverse(fileName.begin(), fileName.end());
            return {fileName};
        }
        
        if(directories.find(path) == directories.end())
            return vector<string>();
        
        if(lsCache.find(path) != lsCache.end() && lsCache[path].size() == directories[path].size())
        {
            // print();
            return lsCache[path];
        }
            
            
        vector<string> result;
        
        for(auto & subDir: directories[path]){
            result.push_back(subDir);
        }
        
        sort(result.begin(), result.end());
        
        lsCache[path] = result;
        // print();
        return result;
    }
    
    void mkdir(string path) 
    {
        // cout<<"mkdir "<<path<<endl;
        if(path[path.size()-1] != '/')
            path += '/';
        
        string prevDir = "/";
        string fullPath = "/";
        int i = 1;
        while(i < path.size()-1)
        {
            string dirName = "";
            while(i < path.size())
            {
                fullPath += path[i];
                if(path[i] == '/')
                    break;
                dirName  += path[i];
                i++;
            }
            // cout<<"prevDir "<<prevDir<<" dirname "<<dirName<<" fullPath "<<fullPath<<endl;
            
            directories[prevDir].insert(dirName);
            
            if(directories.find(fullPath) == directories.end())
            {
                directories[fullPath] = unordered_set<string>();
            }
            
            prevDir = fullPath;
            // printDir();
            i++;
        }
        // print();
        return;
        
    }
    
    void addContentToFile(string filePath, string content) 
    {
        // cout<<"addContentToFile "<<filePath<<" "<<content<<endl;
        if(filePath[filePath.size()-1] != '/')
            filePath += '/';
        
        files.insert(filePath);

        if(directories.find(filePath) == directories.end())
        {
            mkdir(filePath);
            fileContent[filePath] = content;
        }
        else
        {
            fileContent[filePath] += content;
        }
        
        // print();
        
    }
    
    string readContentFromFile(string filePath) 
    {
        if(filePath[filePath.size()-1] != '/')
            filePath += '/';
        return fileContent[filePath];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
