import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { ProfileEstudanteComponent } from './profile-estudante.component';

describe('ProfileEstudanteComponent', () => {
  let component: ProfileEstudanteComponent;
  let fixture: ComponentFixture<ProfileEstudanteComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ ProfileEstudanteComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(ProfileEstudanteComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
