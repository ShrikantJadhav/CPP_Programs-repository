#include<iostream>
#include<experimental/filesystem>

using namespace std;
namespace fs = std::experimental::filesystem;

void displayPathInfo(const fs::path& pathToShow)
{
  cout<<"Displaying path details for : "<<pathToShow<<endl;
  cout<<"------------------------------- "<<endl;
  cout<<"Parts of the Path :"<<endl;

  for(const auto& i : pathToShow )
  {
    cout<<"\tPart : "<<i<<endl;
  }

  cout<<"Attributes of this Path:"<<endl;
  cout<<"------------------------------- "<<endl;
  cout<<"exists() : "<<fs::exists(pathToShow)<<endl;
  cout<<"root_name() : "<<pathToShow.root_name()<<endl;
  cout<<"root_path() : "<<pathToShow.root_path()<<endl;
  cout<<"relative_path() : "<<pathToShow.relative_path()<<endl;
  cout<<"parent_path() : "<<pathToShow.parent_path()<<endl;
  cout<<"filename() : "<<pathToShow.filename()<<endl;
  cout<<"stem() : "<<pathToShow.stem()<<endl;
  cout<<"extension() : "<<pathToShow.extension()<<endl;
}

std::string getPipeString(int level)
{
  string pipeStr = "|"; 
  for(int i = 1; i < level; ++i)
  {
    string tmp(3,' ');
    pipeStr += tmp;
    pipeStr += "|";
  }
  return pipeStr;
}

void displayDirTreeUtil(const fs::path& pathToShow,
                    int level)
{
  if( fs::exists(pathToShow) &&
      fs::is_directory(pathToShow) )
  {
    string strPipe = getPipeString(level);
    string strSpace(3,'-');
    for(const auto& entry : fs::directory_iterator(pathToShow) )
    {
      if( fs::is_directory(entry.status()) )
      {
        cout<<strPipe<<strSpace<<entry.path().filename()<<endl;
        displayDirTreeUtil(entry.path(),level+1);
      }
      else if(fs::is_regular_file(entry.status()) )
      {
        cout<<strPipe<<strSpace<<entry.path().filename()<<endl;
      }
    }
  }
}

void displayDirTree(const fs::path& pathToShow)
{
  if( fs::is_directory(pathToShow) )
  {
      cout<<"---------------------------------"<<endl;
      cout<<"[+]"<<pathToShow<<endl;
  }
  displayDirTreeUtil(pathToShow,1);
}

int main(int argc, char* argv[])
{
  fs::path pathToShow{(argc >= 2) ? argv[1] : fs::current_path()};
  displayPathInfo(pathToShow);

  displayDirTree(pathToShow);
  return 0;
}
