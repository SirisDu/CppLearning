// tvfm.h
// Tv and Remote classes using a friend member

#pragma once

class Tv;                       // forward declaration

class Remote
{
public:
	enum State { Off, On };
	enum { MinVal, MaxVal = 20 };
	enum { Antenna, Cable };
	enum { TV, DVD };

	Remote(int mode = TV) : mode_(mode) {}
	virtual ~Remote() {}

	bool volup(Tv& tv);         // prototype only
	bool voldowm(Tv& tv);
	void onoff(Tv& tv);
	void chanup(Tv& tv);
	void chandown(Tv& tv);
	void set_chan(Tv& tv, int channel);
	void set_mode(Tv& tv);
	void set_input(Tv& tv);

private:
	int mode_;;
};

class Tv
{
public:
	friend void Remote::set_chan(Tv& tv, int channel);

	enum { Off, On };
	enum { MinVal, MaxVal = 20 };
	enum { Antenna, Cable };
	enum { TV, DVD };

	Tv(int state = Off, int maxchannel = 125) : state_(state), volume_(5),
		maxchannel_(maxchannel), channel_(2), mode_(Cable), input_(TV) {}
	virtual ~Tv() {}

	void onoff() { state_ = (state_ == On) ? Off : On; }
	bool ison() const { return state_ == On; }
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() { mode_ = (mode_ == Antenna) ? Cable : Antenna; }
	void set_input() { input_ = (input_ == TV) ? DVD : TV; }
	void settings() const;      // display all settings

private:
	int state_;                 // on or off
	int volume_;                // assumed to be digitized
	int maxchannel_;            // maximum number of channels
	int channel_;               // current channel setting
	int mode_;                  // broadcast or cable
	int input_;
};

// Remote methods as inline functions
inline bool Remote::volup(Tv& tv) { return tv.volup(); }
inline bool Remote::voldowm(Tv& tv) { return tv.voldown(); }
inline void Remote::onoff(Tv& tv) { tv.onoff(); }
inline void Remote::chanup(Tv& tv) { tv.chanup(); }
inline void Remote::chandown(Tv& tv) { tv.chandown(); }
inline void Remote::set_chan(Tv& tv, int channel) { tv.channel_ = channel; }
inline void Remote::set_mode(Tv& tv) { tv.set_mode(); }
inline void Remote::set_input(Tv& tv) { tv.set_input(); }
