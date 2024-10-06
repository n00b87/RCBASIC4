function CreateSound(byref buffer, buffer_size, vol)
function LoadSound(snd_file$)
sub LoadMusic(music_file$)
sub PlaySound(slot, channel, loops)
sub PlaySoundTimed(slot, channel, loops, ms)
sub PlayMusic(mLoops)
sub PauseSound(channel)
sub ResumeSound(channel)
sub PauseMusic()
sub ResumeMusic()
sub DeleteSound(slot)
sub DeleteMusic()
sub FadeMusicIn(fade_time, loops)
sub FadeMusicOut(fade_time)
function MusicExists()
sub SetMusicVolume(vol)
function GetMusicVolume()
sub SetMusicPosition(pos)
function GetMusicPosition()
sub RewindMusic()
sub SetSoundChannels(max_channels)
function NumSoundChannels()
function SoundIsEnabled()
function SoundExists(slot)
sub SetChannelVolume(channel, vol)
function GetChannelVolume(channel)
sub SetSoundVolume(slot, vol)
function GetSoundVolume(slot)
sub StopMusic()
sub StopSound(channel)
function SetChannelPanning(channel, left_value, right_value)
function SetChannelDistance(channel, dist_value)
function ChannelIsPlaying(channel)
function ChannelIsPaused(channel)
function QueryAudioSpec(ByRef freq, ByRef format, ByRef channels)
function MusicIsPlaying()
function SetChannelSpacePosition(channel, angle, distance)