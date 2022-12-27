package csp;

/**
 * Class representing music search criteria (level, speed, musicCharacter)
 * provided by the user. Contains utility members (numResults, allOptionsUsed)
 */
public class SearchOptions {
	// level is never null, due to input validation in App.java
	private String level;
	private String speed;
	private String musicCharacter;
	private int numResults;
	private boolean allOptionsUsed;

	public String getLevel() {
		return level;
	}

	public void setLevel(String level) {
		this.level = level;
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

	public void setMusicCharacter(String character) {
		this.musicCharacter = character;
	}

	public int getNumResults() {
		return numResults;
	}

	public void setNumResults(int numResults) {
		this.numResults = numResults;
	}

	public boolean isAllOptionsUsed() {
		return allOptionsUsed;
	}

	public void setAllOptionsUsed(boolean allOptionsUsed) {
		this.allOptionsUsed = allOptionsUsed;
	}
}
