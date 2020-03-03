#include "DynamicObject.h"

/**
 * Constructor
 */
DynamicObject::DynamicObject () {
}
/**
 * Constructor with specified initial coordinates for a player or a ghost
 */
DynamicObject::DynamicObject ( int x, int y) : init_coords ( make_pair ( x, y) ), coords ( make_pair ( x, y) ), next_coords ( make_pair ( x, y) ), cur_dir ( LEFT ) {
}
/**
 * Assignment operator
 */
DynamicObject & DynamicObject::operator = ( const DynamicObject & other ){
    init_coords = other.init_coords;
    prev_coords = other.prev_coords;
    coords      = other.coords;
    next_coords = other.next_coords;
    cur_dir     = other.cur_dir;
    next_dir    = other.next_dir;
    return * this;
}
/**
 * Method returns value of xy coordinates
 */
pair < int, int > DynamicObject::getXY () const {
    return coords;
}
/**
 * Method moves dynamic object one tile to direction where it heads.
 * @param[in] dir, direction for a dynamic object to head: LEFT, DOWN, UP, RIGHT
 */
void DynamicObject::moveDir ( Direction dir){
    next_dir = dir;
}
/**
 * Method moves DynamicObject one tile to direction where it heads.
 * @param[in] dir, direction for a DynamicObject to head: LEFT, DOWN, UP, RIGHT
 */
bool DynamicObject::move ( const map< pair<int, int>, shared_ptr<GameObject> > & gameObject ) {

    prev_coords = coords;

    switch ( next_dir )
    {
        case UP:
            next_coords.second--;
            break;
        case DOWN:
            next_coords.second++;
            break;
        case LEFT:
            next_coords.first--;
            break;
        case RIGHT:
            next_coords.first++;
            break;
    }

    GameObjectType type = CDefault;
    auto objectType = gameObject.find( next_coords );
    if( objectType != gameObject.end() )
        type = objectType->second->getGameObjectType();

    switch ( type )
    {
        case CWall:
            break;
        default:
            coords = next_coords;
            cur_dir = next_dir;
            return true;
    }

    pair < int, int > tmp_coords ( coords );
    if ( next_dir != cur_dir )
    {
        switch ( cur_dir )
        {
            case LEFT:
                tmp_coords.first--;
                break;
            case RIGHT:
                tmp_coords.first++;
                break;
            case UP:
                tmp_coords.second--;
                break;
            case DOWN:
                tmp_coords.second++;
                break;
        }

        type = CDefault;
        objectType = gameObject.find( tmp_coords );
        if( objectType != gameObject.end() )
            type = objectType->second->getGameObjectType();

        switch ( type )
        {
            case CWall:
                break;
            default:
                coords = tmp_coords;
                next_coords = coords;
                return true;
        }

    }

    next_coords = coords;
    return false;
}
/**
 * Method  initializes coordinates of a dynamic object
 * @param[in] xy, pair of values x and y on a coordinate
 */
void DynamicObject::setInitCoords ( pair < int, int > xy ) {
    init_coords = xy;
    coords = xy;
    next_coords = xy;
}