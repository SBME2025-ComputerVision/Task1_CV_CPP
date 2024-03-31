#include "activecontourcontroller.h"
#include "config.h"
#include "Helpers/helpers.h"

ActiveContourController::ActiveContourController():Controller()
{

}

QImage ActiveContourController::uploadImg(){
 QString path = Helpers::openFile();
 if(!path.isEmpty()){
     QImage image(path);
     return image;
 }

 return QImage(0);
}
