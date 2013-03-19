#include "dcrawqt.h"

DcRawQT::DcRawQT()
{
    p=0;
    showProgress = false;
//	memset(chistogram, 0, sizeof(chistogram));
}

DcRawQT::~DcRawQT()
{
    qDebug("~DcRawQT");

    if(p)
    {
        if (p->meta_data) free (p->meta_data);
        if (p->ofname) free (p->ofname);
        if (p->oprof) free (p->oprof);
        if (p->image) free (p->image);
        delete p;
    }

}

/*
this is the method used to call into the original 'main' function.  its the bridge into the 
dcraw 'C' code.
*/
int DcRawQT::dcrawmain (int argc, const char **argv, QByteArray *imageArray)
{
    int retVal = themain(argc, argv, imageArray);

	buildHistogram();

	return retVal;
}




/*
Calls dcrawqt and determines if the supplied filename is a supported raw image
file format
*/
bool DcRawQT::IsRaw(QString filename)
{
    QStringList args;

    args += "dcrawqt";
    args += "-i";
    args += "-v";
    args += "-c";
    args += filename;

    int argc;
    char **argv;

    argc = BuildCommandLine(args, &argv);

    if(0 == dcrawmain(argc, (const char **)argv, 0))
	{
        return true;
	}

    return false;
}

QString DcRawQT::Identify(QString filename)
{
    QStringList args;

    args += "dcrawqt";
    args += "-i";
    args += "-v";
    args += filename;

    int argc;
    char **argv;//[2048];

    argc = BuildCommandLine(args, &argv);

    if(0 == dcrawmain(argc, (const char **)argv, new QByteArray()))
        return identifyInformation;

    return identifyInformation;
}

QByteArray *DcRawQT::GetImage(QString filename)
{
    QStringList args;


    args += "dcrawqt";
    args += "-T";
    args += "-c";

    return GetImage(filename, args);

}

QByteArray *DcRawQT::GetImage(QString filename, QStringList args)
{

    int argc;
    char **argv;

	args += filename;
    argc = BuildCommandLine(args, &argv);

	return GetImage(argc, argv);

}

QByteArray *DcRawQT::GetImage(int argc, char *argv[])
{
    QByteArray *imageArray = new QByteArray();

    if(0 == dcrawmain(argc, (const char **)argv, imageArray))
	{
		buildHistogram();
        return imageArray;
	}
    return 0;

}

bool DcRawQT::GetRawImage(QString filename)
{
    QStringList args;


    args += "dcrawqt";
    args += "-T";
    args += "-c";

    return GetRawImage(filename, args);

}
bool DcRawQT::GetRawImage(QString filename, QStringList args)
{
    int argc;
    char **argv;


	if(args.contains("-i")){
		args.removeOne("-i");
		qDebug("-i passed to GetRawImage");
	}

    args += filename;
    argc = BuildCommandLine(args, &argv);

	if(GetRawImage(argc, argv))
	{
		buildHistogram();

		return true;
	}

	return false;


}

bool DcRawQT::GetRawImage(int argc, char *argv[])
{
    if(0 == dcrawmain(argc, (const char **)argv, 0))
    {
        return true;
    }

    return false;
}



void DcRawQT::buildHistogram()
{
	for(int i=0; i < p->colors; i++)
    {
        for(int j=0; j < 8192; j++)
        {
           histogram[i][j] = p->histogram[i][j];
        }
    }
}



QByteArray *DcRawQT::GetThumbNail(QString filename)
{
    QStringList args;

    args += "dcrawqt";
    args += "-e";
    args += "-c";

    return GetThumbNail(filename, args);
}

QByteArray *DcRawQT::GetThumbNail(QString filename, QStringList args)
{
    QByteArray *imageArray = new QByteArray();
    int argc;
    char **argv;

    args += filename;
    argc = BuildCommandLine(args, &argv);

    if(0 == dcrawmain(argc, (const char **)argv, imageArray))
        return imageArray;

    return 0;

}

int DcRawQT::BuildCommandLine(QStringList argsList, char*** argv)
{

    int argc = argsList.size();

    char **tempargs = (char **) new char*[argc+1];
    memset(tempargs,0,sizeof(char *)*(argc+1));

    for(int i=0; i < argsList.size(); i++)
    {
        QByteArray temparr = argsList.at(i).toUtf8(); 
		char *temp = temparr.data();
		
		tempargs[i] = new char[argsList.at(i).size() + 1];
        memset(tempargs[i],0,sizeof(char) * argsList.at(i).size()+ 1);
        memcpy(tempargs[i], temp, sizeof(char) * argsList.at(i).size());
    }

	*argv = tempargs;
    return argc;

}





