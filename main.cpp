#include "egg.h"
fs::file_time_type  lastsync;

vector<fs::path> there_can_be_only_one(vector<string>pa,vector<fs::path>rem)
{
    vector<fs::path>res;
    for(int i=0;i<rem.size();i++)
    {
        if(fs::exists(rem[i])) {
            if(fs::is_directory(rem[i])) {
                fs::remove_all(rem[i]);
            }
            fs::remove(rem[i]);
        }
    }

    for(auto& p: fs::recursive_directory_iterator(pa[0]))
    {
        res.push_back(p);
    }

    for(int i=1;i<pa.size();i++)
    {
        fs::remove_all(pa[i]);
    }

    fs::remove(pa[1]);
    fs::create_directory(pa[1]);
    lastsync=fs::last_write_time(pa[1]);

    for(int i=1;i<pa.size();i++)
    {
        fs::copy(pa[0], pa[i], fs::copy_options::overwrite_existing | fs::copy_options::recursive);
    }
    return res;
}






vector<fs::path> we_are_conected_by_the_one_feeling(vector<string>pa,vector<fs::path>base)
{
    vector<fs::path>res;
    string str;
    for(int i=0;i<base.size();i++)
    {
        if(!fs::exists(base[i]))
            res.push_back(base[i]);
    }



    for(int j=0;j<base.size();j++) {
        if (!(fs::last_write_time(base[j]) > lastsync)) {
            str = base[j].string().substr(pa[0].size());
            for (int i = 1; i < pa.size(); i++) {
                if (!fs::exists(pa[i] + str)) {
                    res.push_back(base[j].string());
                    break;
                } else if (fs::last_write_time(pa[i] + str) > lastsync) {
                    if (fs::exists(base[j])) {
                        if (fs::last_write_time(base[j]) < fs::last_write_time(pa[i] + str))
                            fs::copy(pa[i] + str, base[j], fs::copy_options::overwrite_existing);
                        break;
                    }
                }
            }

        }
    }

    for(int i=1;i<pa.size();i++)
    {
        fs::copy(pa[i], pa[0], fs::copy_options::skip_existing | fs::copy_options::recursive);
    }
    return res;
}









void ui() {
    vector<string> paths;
    string str;
    bool rti=0;
    int time_to_sync;
    char ans = 'j';
    cout << "Why do you call me?" << endl;
    do {
        cout << "Опять работать?[y/n]" << endl;
        cin >> ans;
    } while (!cin.fail() && ans != 'y' && ans != 'n');


    if (ans == 'y') {
        ans = 'j';
        do {
            cout << "Do you know the rules? [y/n]" << endl;
            cin >> ans;
        } while (!cin.fail() && ans != 'y' && ans != 'n');


        if (ans == 'y') {
            rules_done:
            if (fs::exists("config")) {
                ans = 'j';
                do {
                    cout << "Do you want to change config? [y/n]" << endl;
                    cin >> ans;
                } while (!cin.fail() && ans != 'y' && ans != 'n');
                if(ans=='y'){ system("nano config");}
                cout<<"OK all done wil start now";
                goto start_time_set;
            }
            else {
                ans = 'j';
                do {
                    cout << "Ther is no config may i create it? [y/n]" << endl;
                    cin >> ans;
                } while (!cin.fail() && ans != 'y' && ans != 'n');


                if (ans == 'y') {
                    ans = 'j';
                    system("touch config");
                    do {
                        cout << "Done!" << endl << "Do you want to change config? [y/n]" << endl;
                        cin >> ans;
                    } while (!cin.fail() && ans != 'y' && ans != 'n');
                    if (ans == 'y')
                    {
                        try { system("nano config"); }
                        catch (const std::exception& e) { e.what(); }
                        cout<<"OK all done wil start now";
                        goto start_time_set;
                    }
                    else {
                        cout << "Ok change it yourself and restart me, see ya";
                        return;
                    }
                } else {
                    ans = 'j';
                    do {
                        cout << "May be enter all paths here now?[y/n]" << endl;
                        cin >> ans;
                    } while (!cin.fail() && ans != 'y' && ans != 'n');
                    if(ans=='y')
                    {
                        rti=1;
                        ans='j';
                        cout<<"OK Lets go, enter all paths and then enter empty line"<<endl;
                        while(1)
                        {
                            cin>>str;
                            if(str=="")
                                break;
                            paths.push_back(str);
                        }
                        cout<<"OK all done wil start now";
                        goto start_time_set;
                    }
                    else
                    {cout<<"I cant work like this. Chao!!!";}

                }

            }
        }
        else
        {
            cout<<"OK. Let me explain\n All dirs will be made like first in config, and then they will sync by this rules:"<<endl;
            cout<<"1. If you add file on any folder it apear in all other folders"<<endl;
            cout<<"2. If you change file on any folder it changes in all other folders"<<endl;
            cout<<"3. If we have some conflict the folders recorded above in the file have priority"<<endl;
            cout<<"Thats all have fun"<<endl;
            goto rules_done;
        }
    }
    else
    {
        cout<<"OK, see ya!";
        return;
    }
    time_to_sync=10;
    start_time_set:
    do {
        cout<<"You want to sync every n minuets. (-1 for sync by press any key here) Enter n: ";
        cin>>time_to_sync;
    } while (!cin.fail() && time_to_sync < -1);




    if(!rti)
    {
        ofstream file;
        string str1,xcin;
        if (fs::exists("config")) {
            vector<string> paths;
            ifstream file("config");
            while (getline(file, str)) {
                if(fs::exists(str)) {
                    paths.push_back(str);
                }/*
                else if(str1.compare("snake.game"))
                {
                    Game g;
                    g.start();
                    g.Play();
                }*/
                else
                    cout<<"no directory :"<<"    "<<str<<endl;
            }
            cout<<"config read successfully"<<endl;
            vector<fs::path> buf;
            buf.clear();
            buf = there_can_be_only_one(paths, buf);
            while (1) {
                if(time_to_sync==-1)
                    cin>>xcin;
                else
                    sleep(time_to_sync*60);
                cout<<"sync"<<endl;
                buf = we_are_conected_by_the_one_feeling(paths, buf);
                buf = there_can_be_only_one(paths, buf);
            }
        }
        else
            cout<<"no config";
    }
}



int main() {
    ui();

}