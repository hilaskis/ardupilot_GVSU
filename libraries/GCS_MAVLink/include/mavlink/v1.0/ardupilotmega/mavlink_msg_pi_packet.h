// MESSAGE PI_PACKET PACKING

#define MAVLINK_MSG_ID_PI_PACKET 188

typedef struct __mavlink_pi_packet_t
{
 float magnitude; ///< Magnitude
 float angle; ///< Angle
 uint8_t target_system; ///< System ID
 uint8_t antenna_type; ///< Antenna Type
} mavlink_pi_packet_t;

#define MAVLINK_MSG_ID_PI_PACKET_LEN 10
#define MAVLINK_MSG_ID_188_LEN 10

#define MAVLINK_MSG_ID_PI_PACKET_CRC 179
#define MAVLINK_MSG_ID_188_CRC 179



#define MAVLINK_MESSAGE_INFO_PI_PACKET { \
	"PI_PACKET", \
	4, \
	{  { "magnitude", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_pi_packet_t, magnitude) }, \
         { "angle", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_pi_packet_t, angle) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_pi_packet_t, target_system) }, \
         { "antenna_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_pi_packet_t, antenna_type) }, \
         } \
}


/**
 * @brief Pack a pi_packet message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param magnitude Magnitude
 * @param angle Angle
 * @param antenna_type Antenna Type
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pi_packet_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t target_system, float magnitude, float angle, uint8_t antenna_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_PI_PACKET_LEN];
	_mav_put_float(buf, 0, magnitude);
	_mav_put_float(buf, 4, angle);
	_mav_put_uint8_t(buf, 8, target_system);
	_mav_put_uint8_t(buf, 9, antenna_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PI_PACKET_LEN);
#else
	mavlink_pi_packet_t packet;
	packet.magnitude = magnitude;
	packet.angle = angle;
	packet.target_system = target_system;
	packet.antenna_type = antenna_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PI_PACKET_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_PI_PACKET;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PI_PACKET_LEN, MAVLINK_MSG_ID_PI_PACKET_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PI_PACKET_LEN);
#endif
}

/**
 * @brief Pack a pi_packet message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param magnitude Magnitude
 * @param angle Angle
 * @param antenna_type Antenna Type
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pi_packet_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t target_system,float magnitude,float angle,uint8_t antenna_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_PI_PACKET_LEN];
	_mav_put_float(buf, 0, magnitude);
	_mav_put_float(buf, 4, angle);
	_mav_put_uint8_t(buf, 8, target_system);
	_mav_put_uint8_t(buf, 9, antenna_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PI_PACKET_LEN);
#else
	mavlink_pi_packet_t packet;
	packet.magnitude = magnitude;
	packet.angle = angle;
	packet.target_system = target_system;
	packet.antenna_type = antenna_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PI_PACKET_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_PI_PACKET;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PI_PACKET_LEN, MAVLINK_MSG_ID_PI_PACKET_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PI_PACKET_LEN);
#endif
}

/**
 * @brief Encode a pi_packet struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param pi_packet C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pi_packet_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_pi_packet_t* pi_packet)
{
	return mavlink_msg_pi_packet_pack(system_id, component_id, msg, pi_packet->target_system, pi_packet->magnitude, pi_packet->angle, pi_packet->antenna_type);
}

/**
 * @brief Encode a pi_packet struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param pi_packet C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pi_packet_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_pi_packet_t* pi_packet)
{
	return mavlink_msg_pi_packet_pack_chan(system_id, component_id, chan, msg, pi_packet->target_system, pi_packet->magnitude, pi_packet->angle, pi_packet->antenna_type);
}

/**
 * @brief Send a pi_packet message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system System ID
 * @param magnitude Magnitude
 * @param angle Angle
 * @param antenna_type Antenna Type
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_pi_packet_send(mavlink_channel_t chan, uint8_t target_system, float magnitude, float angle, uint8_t antenna_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_PI_PACKET_LEN];
	_mav_put_float(buf, 0, magnitude);
	_mav_put_float(buf, 4, angle);
	_mav_put_uint8_t(buf, 8, target_system);
	_mav_put_uint8_t(buf, 9, antenna_type);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PI_PACKET, buf, MAVLINK_MSG_ID_PI_PACKET_LEN, MAVLINK_MSG_ID_PI_PACKET_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PI_PACKET, buf, MAVLINK_MSG_ID_PI_PACKET_LEN);
#endif
#else
	mavlink_pi_packet_t packet;
	packet.magnitude = magnitude;
	packet.angle = angle;
	packet.target_system = target_system;
	packet.antenna_type = antenna_type;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PI_PACKET, (const char *)&packet, MAVLINK_MSG_ID_PI_PACKET_LEN, MAVLINK_MSG_ID_PI_PACKET_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PI_PACKET, (const char *)&packet, MAVLINK_MSG_ID_PI_PACKET_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_PI_PACKET_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_pi_packet_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, float magnitude, float angle, uint8_t antenna_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, magnitude);
	_mav_put_float(buf, 4, angle);
	_mav_put_uint8_t(buf, 8, target_system);
	_mav_put_uint8_t(buf, 9, antenna_type);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PI_PACKET, buf, MAVLINK_MSG_ID_PI_PACKET_LEN, MAVLINK_MSG_ID_PI_PACKET_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PI_PACKET, buf, MAVLINK_MSG_ID_PI_PACKET_LEN);
#endif
#else
	mavlink_pi_packet_t *packet = (mavlink_pi_packet_t *)msgbuf;
	packet->magnitude = magnitude;
	packet->angle = angle;
	packet->target_system = target_system;
	packet->antenna_type = antenna_type;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PI_PACKET, (const char *)packet, MAVLINK_MSG_ID_PI_PACKET_LEN, MAVLINK_MSG_ID_PI_PACKET_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PI_PACKET, (const char *)packet, MAVLINK_MSG_ID_PI_PACKET_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE PI_PACKET UNPACKING


/**
 * @brief Get field target_system from pi_packet message
 *
 * @return System ID
 */
static inline uint8_t mavlink_msg_pi_packet_get_target_system(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field magnitude from pi_packet message
 *
 * @return Magnitude
 */
static inline float mavlink_msg_pi_packet_get_magnitude(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field angle from pi_packet message
 *
 * @return Angle
 */
static inline float mavlink_msg_pi_packet_get_angle(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field antenna_type from pi_packet message
 *
 * @return Antenna Type
 */
static inline uint8_t mavlink_msg_pi_packet_get_antenna_type(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Decode a pi_packet message into a struct
 *
 * @param msg The message to decode
 * @param pi_packet C-struct to decode the message contents into
 */
static inline void mavlink_msg_pi_packet_decode(const mavlink_message_t* msg, mavlink_pi_packet_t* pi_packet)
{
#if MAVLINK_NEED_BYTE_SWAP
	pi_packet->magnitude = mavlink_msg_pi_packet_get_magnitude(msg);
	pi_packet->angle = mavlink_msg_pi_packet_get_angle(msg);
	pi_packet->target_system = mavlink_msg_pi_packet_get_target_system(msg);
	pi_packet->antenna_type = mavlink_msg_pi_packet_get_antenna_type(msg);
#else
	memcpy(pi_packet, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_PI_PACKET_LEN);
#endif
}
