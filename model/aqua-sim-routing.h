//...

#ifndef AQUA_SIM_ROUTING_H
#define AQUA_SIM_ROUTING_H

#include "ns3/object.h"
#include "ns3/address.h"
#include "ns3/nstime.h"
//#include "ns3/ipv4.h"
//#include "ns3/ipv4-routing-protocol.h"
//#include "ns3/ipv4-static-routing.h"

//#include "aqua-sim-mac.h"
#include "aqua-sim-net-device.h"

namespace ns3 {

class Packet;

class AquaSimRouting : public Object
{	
public:	
/*define common commands for underwater routing protocols*/
  static TypeId GetTypeId(void);
  AquaSimRouting(void);
  virtual ~AquaSimRouting(void);

  virtual void SetNetDevice(Ptr<AquaSimNetDevice> device);

  /*avoid instantiation since UnderwaterRouting's behavior is not defined*/
  virtual void Recv(Ptr<Packet> p);	//handler not implemented
  /*send packet p to next_hop after delay*/
  virtual void SendDown(Ptr<Packet> p, const Address &nextHop, Time delay);
protected:
  /*send packet up to port-demux*/
  virtual void SendUp(Ptr<Packet> p);			//demux not implemented yet.
  /*check if if a dead loop results in the incoming packet*/
  virtual bool IsDeadLoop(Ptr<Packet> p);
  /*check if this node is the next hop*/
  virtual bool AmINextHop(const Ptr<Packet> p);
  /*check if this node is the destination.*/
  virtual bool AmIDst(const Ptr<Packet> p);
  /*check if this node is the source node,
	  * i.e., whose app layer generates this packet.*/
  virtual bool AmISrc(const Ptr<Packet> p);
protected:
  Address m_myAddr;  //the ip address of this node
  Ptr<AquaSimNetDevice> m_device;
  //Ptr<Trace> m_traceTarget;       // Trace Target	TODO need to initiate tracing
  //NsObject *ll;			//pointer to link layer object
  //NsObject *port_dmux;

private:
  //Ptr<AquaSimMac> m_mac;

};  //AquaSimRouting class

}  //namespace ns3

#endif /* AQUA_SIM_ROUTING_H */
