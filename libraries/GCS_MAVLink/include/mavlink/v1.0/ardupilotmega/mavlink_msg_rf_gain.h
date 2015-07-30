// MESSAGE RF_GAIN PACKING

#define MAVLINK_MSG_ID_RF_GAIN 189

typedef struct __mavlink_rf_gain_t
{
 float gain; ///< RF Gain
 uint8_t target_system; ///< System ID
} mavlink_rf_gain_t;

#define MAVLINK_MSG_ID_RF_GAIN_LEN 5
#define MAVLINK_MSG_ID_189_LEN 5

#define MAVLINK_MSG_ID_RF_GAIN_CRC 112
#define MAVLINK_MSG_ID_189_CRC 112



#define MAVLINK_MESSAGE_INFO_RF_GAIN { \
	"RF_GAIN", \
	2, \
	{  { "gain", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_rf_gain_t, gain) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_rf_gain_t, target_system) }, \
         } \
}


/**
 * @brief Pack a rf_gain message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param gain RF Gain
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_rf_gain_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t target_system, float gain)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_RF_GAIN_LEN];
	_mav_put_float(buf, 0, gain);
	_mav_put_uint8_t(buf, 4, target_system);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RF_GAIN_LEN);
#else
	mavlink_rf_gain_t packet;
	packet.gain = gain;
	packet.target_system = target_system;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RF_GAIN_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_RF_GAIN;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RF_GAIN_LEN, MAVLINK_MSG_ID_RF_GAIN_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RF_GAIN_LEN);
#endif
}

/**
 * @brief Pack a rf_gain message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param gain RF Gain
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_rf_gain_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t target_system,float gain)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_RF_GAIN_LEN];
	_mav_put_float(buf, 0, gain);
	_mav_put_uint8_t(buf, 4, target_system);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RF_GAIN_LEN);
#else
	mavlink_rf_gain_t packet;
	packet.gain = gain;
	packet.target_system = target_system;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RF_GAIN_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_RF_GAIN;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RF_GAIN_LEN, MAVLINK_MSG_ID_RF_GAIN_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RF_GAIN_LEN);
#endif
}

/**
 * @brief Encode a rf_gain struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param rf_gain C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_rf_gain_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_rf_gain_t* rf_gain)
{
	return mavlink_msg_rf_gain_pack(system_id, component_id, msg, rf_gain->target_system, rf_gain->gain);
}

/**
 * @brief Encode a rf_gain struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param rf_gain C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_rf_gain_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_rf_gain_t* rf_gain)
{
	return mavlink_msg_rf_gain_pack_chan(system_id, component_id, chan, msg, rf_gain->target_system, rf_gain->gain);
}

/**
 * @brief Send a rf_gain message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system System ID
 * @param gain RF Gain
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_rf_gain_send(mavlink_channel_t chan, uint8_t target_system, float gain)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_RF_GAIN_LEN];
	_mav_put_float(buf, 0, gain);
	_mav_put_uint8_t(buf, 4, target_system);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RF_GAIN, buf, MAVLINK_MSG_ID_RF_GAIN_LEN, MAVLINK_MSG_ID_RF_GAIN_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RF_GAIN, buf, MAVLINK_MSG_ID_RF_GAIN_LEN);
#endif
#else
	mavlink_rf_gain_t packet;
	packet.gain = gain;
	packet.target_system = target_system;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RF_GAIN, (const char *)&packet, MAVLINK_MSG_ID_RF_GAIN_LEN, MAVLINK_MSG_ID_RF_GAIN_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RF_GAIN, (const char *)&packet, MAVLINK_MSG_ID_RF_GAIN_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_RF_GAIN_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_rf_gain_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, float gain)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, gain);
	_mav_put_uint8_t(buf, 4, target_system);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RF_GAIN, buf, MAVLINK_MSG_ID_RF_GAIN_LEN, MAVLINK_MSG_ID_RF_GAIN_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RF_GAIN, buf, MAVLINK_MSG_ID_RF_GAIN_LEN);
#endif
#else
	mavlink_rf_gain_t *packet = (mavlink_rf_gain_t *)msgbuf;
	packet->gain = gain;
	packet->target_system = target_system;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RF_GAIN, (const char *)packet, MAVLINK_MSG_ID_RF_GAIN_LEN, MAVLINK_MSG_ID_RF_GAIN_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RF_GAIN, (const char *)packet, MAVLINK_MSG_ID_RF_GAIN_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE RF_GAIN UNPACKING


/**
 * @brief Get field target_system from rf_gain message
 *
 * @return System ID
 */
static inline uint8_t mavlink_msg_rf_gain_get_target_system(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field gain from rf_gain message
 *
 * @return RF Gain
 */
static inline float mavlink_msg_rf_gain_get_gain(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Decode a rf_gain message into a struct
 *
 * @param msg The message to decode
 * @param rf_gain C-struct to decode the message contents into
 */
static inline void mavlink_msg_rf_gain_decode(const mavlink_message_t* msg, mavlink_rf_gain_t* rf_gain)
{
#if MAVLINK_NEED_BYTE_SWAP
	rf_gain->gain = mavlink_msg_rf_gain_get_gain(msg);
	rf_gain->target_system = mavlink_msg_rf_gain_get_target_system(msg);
#else
	memcpy(rf_gain, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_RF_GAIN_LEN);
#endif
}
