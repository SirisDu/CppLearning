// tv.h
// Tv nd Remote classes

#pragma once

class Remote;

class Tv
{
public:
	friend class Remote;        // Remote can access Tv private parts

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
	void change_remote_mode(Remote& remote);

private:
	int state_;                 // on or off
	int volume_;                // assumed to be digitized
	int maxchannel_;            // maximum number of channels
	int channel_;               // current channel setting
	int mode_;                  // broadcast or cable
	int input_;
};

class Remote
{
public:
	friend class Tv;            // Tv can access Remote private parts

	enum { Default, Interactive };

	Remote(int mode = Tv::TV, int remote_mode = Default)
		: mode_(mode), remote_mode_(remote_mode) {}
	virtual ~Remote() {}

	bool volup(Tv& tv) { return tv.volup(); }
	bool voldowm(Tv& tv) { return tv.voldown(); }
	void onoff(Tv& tv) { tv.onoff(); }
	void chanup(Tv& tv) { tv.chanup(); }
	void chandown(Tv& tv) { tv.chandown(); }
	void set_chan(Tv& tv, int channel) { tv.channel_ = channel; }
	void set_mode(Tv& tv) { tv.set_mode(); }
	void set_input(Tv& tv) { tv.set_input(); }
	void show_mode() const;

private:
	int mode_;                  // controls TV or DVD
	int remote_mode_;           // Default or Interactive
};
