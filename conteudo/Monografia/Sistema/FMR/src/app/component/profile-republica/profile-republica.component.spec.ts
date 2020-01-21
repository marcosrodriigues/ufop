import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { ProfileRepublicaComponent } from './profile-republica.component';

describe('ProfileRepublicaComponent', () => {
  let component: ProfileRepublicaComponent;
  let fixture: ComponentFixture<ProfileRepublicaComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ ProfileRepublicaComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(ProfileRepublicaComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
