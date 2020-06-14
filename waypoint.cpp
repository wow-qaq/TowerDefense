#include "waypoint.h"

WayPoint::WayPoint(QPoint pos): w_pos(pos),w_nextWayPoint(NULL)
{

}
void WayPoint::setNextWayPoint(WayPoint *nextPoint){
    w_nextWayPoint = nextPoint;
}
WayPoint*  WayPoint::nextWayPoint() const{
    return w_nextWayPoint;
}
const QPoint WayPoint::pos() const{
    return w_pos;
}
