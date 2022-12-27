package csp;

/**
 * Class representing a piano piece, given attributes (level, period, title,
 * composer, speed, musicCharacter) from a CSV file
 */
public class PianoPiece {

	private String level;
	private String period;
	private String title;
	private String composer;
	private String speed;
	private String musicCharacter;

	public PianoPiece(String level, String period, String title, String composer, String speed, String musicCharacter) {
		this.level = level;
		this.period = period;
		this.title = title;
		this.composer = composer;
		this.speed = speed;
		this.musicCharacter = musicCharacter;
	}

	public String getLevel() {
		return level;
	}

	public void setLevel(String level) {
		this.level = level;
	}

	public String getPeriod() {
		return period;
	}

	public void setPeriod(String period) {
		this.period = period;
	}

	public String getTitle() {
		return title;
	}

	public void setTitle(String title) {
		this.title = title;
	}

	public String getComposer() {
		return composer;
	}

	public void setComposer(String composer) {
		this.composer = composer;
	}

	public String getSpeed() {
		return speed;
	}

	public void setSpeed(String speed) {
		this.speed = speed;
	}

	public String getMusicCharacter() {
		return musicCharacter;
	}

	public void setMusicCharacter(String musicCharacter) {
		this.musicCharacter = musicCharacter;
	}

	@Override
	public String toString() {
		return String.format("%-7s %-15s %-10s %-35s %-15s %-3s", level.trim(), speed.trim(), musicCharacter.trim(),
				title.trim(), composer.trim(), period.trim());
	}

}
